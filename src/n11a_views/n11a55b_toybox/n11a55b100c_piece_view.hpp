#pragma once

#include "../../n95a_core_library/n95a55b_toybox_94c_board/piece.hpp"
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
