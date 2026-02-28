#pragma once

#include "../n95a55b_toybox_94c_board/muz_board_model.hpp"

class MuzPositionModel
{


	// ========================================
	// フィールド
	// ========================================

private:     
	/// <summary>
	/// 盤。
	/// </summary>
	MuzBoardModel board_;


	// ========================================
	// アクセッサー
	// ========================================


public:
	/// <summary>
	/// 盤。
	/// </summary>
	/// <returns></returns>
	const MuzBoardModel& get_board() const;

	/// <summary>
	/// 盤。
	/// </summary>
	/// <returns></returns>
	MuzBoardModel& get_board();
};
