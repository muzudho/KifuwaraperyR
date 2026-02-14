// main.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "main.h"
#include <cstdio>    // printf を使うために必要
#include <filesystem>
#include <format>    // C++20～
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>                    // 必要に応じて（カスタム型とか使うとき）
#include <spdlog/async.h>                       // async用
#include <spdlog/sinks/rotating_file_sink.h>    // これ必須！（ログファイルをローテーションするなら）
#include <spdlog/sinks/stdout_color_sinks.h>    // これも必須！（コンソールに色付きで出すなら）
#include <toml++/toml.hpp>

using namespace std;

int main()
{
    namespace fs = std::filesystem;

    try {
        fs::path cwd = fs::current_path();  // これで現在のパスを取る

        // 文字列で表示（一番シンプル）
        std::cout << "現在のカレントディレクトリ: " << cwd.string() << std::endl;

        // もっと綺麗に（Windowsならバックスラッシュ、Unixならスラッシュ）
        std::cout << "native形式: " << cwd.make_preferred().string() << std::endl;

        // スラッシュ統一で表示したい場合
        std::cout << "generic形式: " << cwd.generic_string() << std::endl;


        // プロジェクトルートからconfig.tomlを読む（CMAKE_SOURCE_DIRはCMakeで定義される）
        // もしくは std::filesystem::current_path() で実行時カレントから
        auto config = toml::parse_file("config.toml");

        // loggingセクション取る
        auto logging = config["logging"];
        if (!logging) {
            throw std::runtime_error("No [logging] section in config.toml");
        }

        std::string level_str = logging["level"].value_or("info");
        spdlog::level::level_enum log_level = spdlog::level::from_str(level_str);
        cout << "level_str = " << level_str << endl;



        // 最初に1回だけ: スレッドプール初期化（キューサイズ8192、バックグラウンドスレッド1個がデフォルトで十分）
        spdlog::init_thread_pool(8192, 1);  // キュー8192個、バックエンドスレッド1つ（増やしてもOK）

        // ローテーション設定: ファイル名, 最大サイズ(バイト), 最大ファイル数
        // 例: 5MB超えたら回転、最大3ファイル残す（rotating.txt → rotating.txt.1 → rotating.txt.2 → 古いのは消える）
        auto max_size = 1024 * 1024 * 5;    // 5MBで回転
        auto max_files = 5;                 // 最大5ファイル残す


        // ［コンソールシンク］


        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::info);  // コンソールはinfo以上だけとか


        // ［ファイルシンク］


        // rotating sinkを作成（_mt じゃなくて _st でもOK、async_loggerがスレッド安全にするから）
        // （_mt = multi-threaded）
        auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
            "logs/myapp.log",   // ベースファイル名（フォルダは事前に作っとけ、またはspdlog 1.5+なら自動作成）
            max_size,
            max_files
        );


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

        // ログレベルを設定（trace〜critical全部出すならtraceに）
        async_logger->set_level(spdlog::level::trace);  // または info, warn とか

        // フォーマットもカスタムしたいなら（オプション）
        async_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] %v");

        // これでデフォルトloggerにも設定（spdlog::info() でこのloggerを使う）
        spdlog::set_default_logger(async_logger);

        cout << "Hello CMake." << endl;
        std::cout << "Hello, World! from Visual Studio 2026 + CMake\n";
        std::cout << "むずでょ 元気？？（＾～＾）\n";

        printf("ﾊﾛｰﾜｰﾙﾄﾞ！ むずでょ最強www\n");
        std::string s = std::format("HP:{:03d} MP:{:4d} にゃ", 42, 7);
        printf("%s\n", s.c_str());
        // または
        puts(s.c_str());

        // 基本のログ
        spdlog::info("Hello, World! from spdlog + Visual Studio 2026 + CMakeだぜ（＾～＾）");

        // レベル別サンプル
        spdlog::trace("これはtrace（普段は非表示）");
        spdlog::debug("デバッグ情報～");
        spdlog::info("普通の情報 {}", 42);
        spdlog::warn("警告だよ！");
        spdlog::error("エラー発生！ {}", "ヤバい値");
        spdlog::critical("システム死亡寸前！！");

        // もっとカッコよくしたいなら
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");  // 時刻＋色付きレベル

        spdlog::info("むずでょ、今日も元気か？？（＾ω＾）");
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cerr << "spdlog init failed: " << ex.what() << std::endl;
        return 1;
    }

    // 終了時にflush（出力し終わってないログを全部吐く）
    spdlog::shutdown();
    return 0;
}
