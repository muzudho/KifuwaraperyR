#pragma once

#include "../n95a55b_toybox_94c_board/muz_board_model.hpp"
#include "../n95a55b_toybox_95c_hand_stand/muz_hand_stand_collection_model.hpp"
#include "../n95a55b_toybox_105c_turn/color.hpp"
#include "../n95a55b_toybox_105c_turn/muz_turn_model.hpp"

class MuzPositionModel
{


	// ========================================
	// 生成／破棄
	// ========================================


public:
    MuzPositionModel();


	// ========================================
	// フィールド
	// ========================================

private:     
	/// <summary>
	/// 盤の状態を表すぜ（＾～＾）
	/// </summary>
	MuzBoardModel board_;

	/// <summary>
	/// 先手、後手の駒台をまとめて表すぜ（＾～＾） SFEN 形式がそうなってるから（＾～＾）
	/// </summary>
	MuzHandStandCollectionModel hand_stand_collection_;

	/// <summary>
	/// 手番
	/// </summary>
	MuzTurnModel turn_;


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

	/// <summary>
	/// 手番。
	/// </summary>
	/// <returns></returns>
	const MuzTurnModel& get_turn() const { return this->turn_; }
	MuzTurnModel& get_turn() { return this->turn_; }
};
