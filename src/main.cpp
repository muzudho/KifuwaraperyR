// main.cpp :
//      アプリケーションのエントリ ポイントを定義します。
//
#include "main.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    // ワーキング・ディレクトリー表示（スラッシュで統一）
    namespace fs = std::filesystem;
    fs::path cwd = fs::current_path();
    std::cout << "[main] working_directory = " << cwd.generic_string() << std::endl;


    // ロギングの設定


    if (!MuzLoggingService::setup("config.toml"))
    {
        std::cerr << "Logging setup failed. Exiting.\n";
        return 1;
    }


    // 本文


    cout << "Hello KifuwaraperyR." << endl;
    std::cout << "Hello, World! from Visual Studio 2026 + CMake\n";
    std::cout << "むずでょ 元気？？（＾～＾）\n";

    printf("ﾊﾛｰﾜｰﾙﾄﾞ！ むずでょ最強www\n");
    std::string s = std::format("HP:{:03d} MP:{:4d} にゃ", 42, 7);
    printf("%s\n", s.c_str());
    // または
    puts(s.c_str());


    // ロガー


    auto loggingSvc = MuzLoggingService::instance();
    loggingSvc.get_default()->info("Hello, World! from spdlog + Visual Studio 2026 + CMakeだぜ（＾～＾）");

    // レベル別サンプル
    loggingSvc.get_default()->trace("これはtrace（普段は非表示）");
    loggingSvc.get_default()->debug("デバッグ情報～");
    loggingSvc.get_default()->info(std::format("普通の情報 {}", 42));
    loggingSvc.get_default()->warn("警告だよ！");
    loggingSvc.get_default()->error(std::format("エラー発生！ {}", "ヤバい値"));
    loggingSvc.get_default()->fatal("システム死亡寸前！！");
    loggingSvc.get_default()->info("むずでょ、今日も元気か？？（＾ω＾）");

    // ゲームエンジンの実行


    MuzGameEngineService gameEngineSvc;
    gameEngineSvc.initialize_10a();
    gameEngineSvc.main_loop_50a(argc, argv);
    gameEngineSvc.finalize_90a();


    // 終了時にflush（出力し終わってないログを全部吐く）
    MuzLoggingService::shutdown();
    return 0;
}
