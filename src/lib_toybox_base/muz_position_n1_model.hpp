#pragma once

#include "n1_ply.hpp"
#include "n1_color.hpp"
#include "n1_piece.hpp"
#include "n1_hand_piece.hpp"

class MuzPositionN1Model
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


};