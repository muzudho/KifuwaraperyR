#pragma once
#include "muz_default_logger_model.hpp"
#include <cstdio>    // printf を使うために必要
#include <filesystem>
#include <iostream>  // 追加: std::cerr を使うために必要
#include <memory>
#include <spdlog/async.h>                       // async用
#include <spdlog/fmt/ostr.h>                    // 必要に応じて（カスタム型とか使うとき）
#include <spdlog/sinks/rotating_file_sink.h>    // これ必須！（ログファイルをローテーションするなら）
#include <spdlog/sinks/stdout_color_sinks.h>    // これも必須！（コンソールに色付きで出すなら）
#include <spdlog/spdlog.h>
#include <toml++/toml.hpp>
using std::cout;
using std::endl;


class MuzLoggingService
{
public:


    // ========================================
    // シングルトン
    // ========================================


    // 唯一のアクセスポイント（constでも非constでもOK）
    static MuzLoggingService& instance()
    {
        static MuzLoggingService svc;   // 初回呼び出し時に1回だけ生成（スレッドセーフ）
        return svc;
    }


private:


    // ========================================
    // 生成／破棄
    // ========================================


    MuzLoggingService();


public:


    // ========================================
    // フィールド
    // ========================================


    MuzDefaultLoggerModel default_logger;


    // ========================================
    // アクセッサ
    // ========================================


    const MuzDefaultLoggerModel* get_default() const;


    // ========================================
    // メソッド
    // ========================================


    static bool setup(const std::string& config_path = "config.toml");
    static void shutdown();
};