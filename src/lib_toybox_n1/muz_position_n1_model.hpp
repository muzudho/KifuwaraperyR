#pragma once

#include "ply.hpp"
#include "color.hpp"
#include "piece.hpp"
#include "square.hpp"
#include "hand_piece.hpp"

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


	// ========================================
	// アクセッサ
	// ========================================


	/// <summary>
	/// 何手目か
	/// </summary>
	/// <returns></returns>
	Ply GetGamePly();


};