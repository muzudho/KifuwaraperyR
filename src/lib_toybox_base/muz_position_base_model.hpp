//
// 📄 局面の状態を表すクラス
//

#pragma once

#include "../../src/lib_cpp/int.hpp"
#include "../lib_toybox_v1/muz_position_n1_model.hpp"
#include "n1_hand_piece.hpp"
#include "n1_piece_type.hpp"
#include "n1_square_delta.hpp"
#include "n2_char_to_piece_usi.hpp"
#include "n2_hand_ope.hpp"
#include "n2_piece_ope.hpp"
#include "n3_hand_piece_ope.hpp"
#include "n3_square_ope.hpp"
#include <iostream>
#include <map>
#include <optional>
#include <ranges>         // C++20 ranges
#include <string>
#include <string_view>

class MuzPositionBaseModel : public MuzPositionN1Model
{


protected:


	// ========================================
	// フィールド
	// ========================================


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
	Color GetTurn();


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
	Piece GetPiece(const Square sq);

	void SetPiece(const Piece piece, const Square sq);

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

	void SetHand(const HandPiece hp, const Color c, const int num);

	void SetHand(const Piece piece, const int num);


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
	int ParsePly(std::string_view ply_str);
};
