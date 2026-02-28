#pragma once

#include "../n95a55b_toybox_94c_board/muz_board_model.hpp"
#include "../n95a55b_toybox_95c_hand_stand/muz_hand_stand_collection_model.hpp"

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

	/// <summary>
	/// 先手、後手の駒台をまとめて表すぜ（＾～＾） SFEN 形式がそうなってるから（＾～＾）
	/// </summary>
	MuzHandStandCollectionModel hand_stand_collection_;


	// ========================================
	// アクセッサー
	// ========================================


public:
	/// <summary>
	/// 盤。
	/// </summary>
	/// <returns></returns>
	const MuzBoardModel& get_board() const;
	MuzBoardModel& get_board();

	/// <summary>
	/// 駒台。
	/// </summary>
	/// <returns></returns>
	const MuzHandStandCollectionModel& get_hand_stand_collection() const { return this->hand_stand_collection_; }
	MuzHandStandCollectionModel& get_hand_stand_collection() { return this->hand_stand_collection_; }
};
