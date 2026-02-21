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


    bool is_quit() const { return is_quit_; }
    void set_quit(bool value) { is_quit_ = value; }
};
