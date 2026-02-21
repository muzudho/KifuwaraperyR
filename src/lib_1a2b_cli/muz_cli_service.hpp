#pragma once

class MuzCliService
{

public:
    // ========================================
    // 主要なメソッド
    // ========================================

    void main_loop(int argc, char* argv[]);

    void process_command(const std::string& cmd);
};