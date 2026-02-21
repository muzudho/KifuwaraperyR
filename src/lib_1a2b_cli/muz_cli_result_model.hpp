#pragma once

class MuzCliResultModel
{


    // ========================================
    // フィールド
    // ========================================


private:

    bool is_quit_;


public:


    // ========================================
    // アクセッサー
    // ========================================


    bool IsQuit() const { return is_quit_; }
    void SetQuit() { is_quit_ = true; }
};
