//
// 📄 局面の状態を表すクラス
//

#pragma once

#include "char_to_piece_usi.hpp"
#include "color.hpp"
#include "file.hpp"
#include "hand.hpp"
#include "ply.hpp"
#include "piece.hpp"
#include "rank.hpp"
#include "square.hpp"
#include "square_delta.hpp"
#include <charconv>       // std::from_chars
#include <ranges>         // C++20 ranges
#include <string_view>
#include <optional>
#include <iostream>

class MuzPositionBaseModel
{


protected:


	// ========================================
	// フィールド
	// ========================================


	/// <summary>
	/// 何手目か。時間管理に使用する
	/// </summary>
	Ply m_gamePly_;

	/// <summary>
	/// 手番
	/// </summary>
	Color m_turn_;

	/// <summary>
	/// 各マスの駒
	/// </summary>
	Piece m_piece_[SquareNum];

	/// <summary>
	/// 先後対局者別の手駒
	/// </summary>
	Hand m_hand_[g_COLOR_NUM];


	// ========================================
	// アクセッサ
	// ========================================


	/// <summary>
	/// 次の手番
	/// </summary>
	/// <returns></returns>
	Color GetTurn() const;


	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Ply GetGamePly() const;


	/// <summary>
	/// 
	/// </summary>
	/// <param name="ply"></param>
	void SetStartPosPly(const Ply ply);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="sq"></param>
	/// <returns></returns>
	Piece GetPiece(const Square sq) const;


	/// <summary>
	/// 持ち駒
	/// </summary>
	/// <typeparam name="CLR"></typeparam>
	/// <returns></returns>
	template<Color CLR>
	Hand GetHand() const
	{
		return this->m_hand_[CLR];
	}
	Hand GetHand(const Color c) const;


	// ========================================
	// 主要メソッド
	// ========================================


	/// <summary>
	/// 局面をセット
	/// </summary>
	/// <param name="sfen"></param>
	void Set(std::string_view sfen);
	bool ParseBoard(std::string_view board_str);
	bool ParseTurn(std::string_view turn_str);
	bool ParseHand(std::string_view hand_str);
	std::optional<int> ParsePly(std::string_view ply_str);
};
