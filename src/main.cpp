// main.cpp :
//      アプリケーションのエントリ ポイントを定義します。
//

#include "main.h"
#include "app_layer/logging_setup.h"
#include <cstdio>    // printf を使うために必要
#include <filesystem>
#include <format>    // C++20～
#include <spdlog/spdlog.h>

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


        // ロギングの設定


        if (!logging_setup("config.toml"))
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
    logging_shutdown();
    return 0;
}
