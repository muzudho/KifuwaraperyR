#include "muz_logging_service.hpp"


// ========================================
// 生成／破棄
// ========================================


MuzLoggingService::MuzLoggingService()
{
    this->default_logger = MuzDefaultLoggerModel();
}


// ========================================
// アクセッサ
// ========================================


const MuzDefaultLoggerModel* MuzLoggingService::get_default() const
{
    return &this->default_logger;
}


// ========================================
// メソッド
// ========================================


bool MuzLoggingService::setup(const std::string& config_path)
{
    // プロジェクトルートからconfig.tomlを読む（CMAKE_SOURCE_DIRはCMakeで定義される）
    // もしくは std::filesystem::current_path() で実行時カレントから
    auto config = toml::parse_file("config.toml");

    if (config.empty())
    {
        std::cerr << "config.toml が読めなかった！\n";
        return false;
    }

    // loggingセクション取る
    auto logging = config["logging"];
    if (!logging) {
        throw std::runtime_error("No `[logging]` section in config.toml");
    }


    // ［デフォルト設定］


    std::string default_log_level_str = logging["level"].value_or("info");
    std::string default_pattern_str = logging["pattern"].value_or("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] %v");
    auto queue_size = logging["queue_size"].value_or<std::int64_t>(8192); // 既定値：8192 Bytes

    // 最初に1回だけ: スレッドプール初期化（キューサイズ8192、バックグラウンドスレッド1個がデフォルトで十分）
    spdlog::init_thread_pool(queue_size, 1);  // キュー8192個、バックエンドスレッド1つ（増やしてもOK）


    // ［コンソールシンク］


    std::string console_level_str = logging["console"]["level"].value_or(default_log_level_str);
    spdlog::level::level_enum console_log_level = spdlog::level::from_str(console_level_str);
    cout << "(^q^) [logging > console] level = " << console_level_str << endl;

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(console_log_level);  // コンソールはinfo以上だけとか


    // ［ファイルシンク］


    // ベースファイル名（フォルダは事前に作っとけ、またはspdlog 1.5+なら自動作成）
    std::string path_str = logging["file"]["path"].value_or("logs/myapp.log");

    std::string file_log_level_str = logging["file"]["level"].value_or(default_log_level_str);
    spdlog::level::level_enum file_log_level = spdlog::level::from_str(file_log_level_str);
    cout << "(^q^) [logging > file] level = " << file_log_level_str << ", path = " << path_str << endl;

    // ローテーション設定: ファイル名, 最大サイズ(バイト), 最大ファイル数
    // 例: 5MB超えたら回転、最大3ファイル残す（rotating.txt → rotating.txt.1 → rotating.txt.2 → 古いのは消える）
    //auto max_size = 1024 * 1024 * 5;    // 5MBで回転
    auto max_size_mb = logging["file"]["max_size_mb"].value_or<std::int64_t>(5); // 既定値：5MB
    auto max_size = max_size_mb * 1024 * 1024;    // 指定のMBで回転
    auto max_files = logging["file"]["max_files"].value_or<std::int64_t>(5);   // 最大何ファイル残すか。既定値：5

    // rotating sinkを作成（_mt じゃなくて _st でもOK、async_loggerがスレッド安全にするから）
    // （_mt = multi-threaded）
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        path_str,
        max_size,
        max_files
    );
    // ログレベルを設定（trace〜critical全部出すならtraceに）
    file_sink->set_level(file_log_level);


    // ［シンク］合成


    std::vector<spdlog::sink_ptr> sinks{ console_sink, file_sink };


    // ［非同期ロガー］


    // マルチスレッド対応のローテーション async_logger 作成（名前は任意、spdlog::thread_pool() を渡す）
    auto async_logger = std::make_shared<spdlog::async_logger>(
        "app_logger",               // loggerの名前（任意）
        sinks.begin(),              // シンクの範囲指定
        sinks.end(),
        spdlog::thread_pool(),      // グローバルプール使う
        spdlog::async_overflow_policy::block  // キュー満杯時はブロック（安全重視） or overrun_oldest（古いログ捨てる）
    );

    // フォーマットもカスタムしたいなら（オプション）
    async_logger->set_pattern(default_pattern_str);

    // これでデフォルトloggerにも設定（spdlog::info() でこのloggerを使う）
    spdlog::set_default_logger(async_logger);

    return true;  // 成功
}


void MuzLoggingService::shutdown()
{
    spdlog::shutdown();
}
