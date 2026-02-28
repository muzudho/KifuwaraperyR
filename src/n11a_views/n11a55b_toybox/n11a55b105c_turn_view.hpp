#pragma once

#include "../../n95a_core_library/n95a55b_toybox_105c_turn/color.hpp"
#include <string>

class MuzTurnView
{
public:


    // ========================================
    // 主要メソッド
    // ========================================


    /// <summary>
    /// 手番の色を b か w の文字列に変換するぜ（＾～＾）
    /// </summary>
    static std::string to_code(const Color color);
};
