#pragma once

#include "../../n95a_core_library/lib_55a_toybox_94b_board/piece.hpp"
#include <string>

class MuzPieceView
{
public:


    // ========================================
    // 主要メソッド
    // ========================================


    /// <summary>
    /// 駒を文字列に変換して表示するぜ（＾～＾）
    /// </summary>
    static std::string pretty(const Piece piece);
};
