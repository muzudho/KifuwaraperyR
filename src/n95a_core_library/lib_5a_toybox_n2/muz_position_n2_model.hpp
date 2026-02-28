#pragma once

// MuzPositionN2Model では使ってないヘッダーファイルでも、他のクラスが MuzPositionN2Model をインクルードすれば lib_5a_toybox_n2 のヘッダーファイルが全部付いてくるようにします。
#include "../lib_5a_toybox_n1/muz_position_n1_model.hpp"
#include "../n95a55b_toybox_94c_board/char_to_piece_usi.hpp"
#include "../n95a55b_toybox_95c_hand_stand/muz_hand_stand_collection_model.hpp"
#include "hand_piece_ope.hpp"
#include "piece_ope.hpp"
#include "piece_types.hpp"
#include "piece_type_ope.hpp"

class MuzPositionN2Model : public MuzPositionN1Model
{


	// ========================================
	// フィールド
	// ========================================


protected:
	/// <summary>
    /// 先手、後手の駒台をまとめて表すぜ（＾～＾） SFEN 形式がそうなってるから（＾～＾）
    /// </summary>
	MuzHandStandCollectionModel hand_stand_collection_;


	// ========================================
	// アクセッサ
	// ========================================


public:
	const MuzHandStandCollectionModel& get_hand_stand_collection() const { return this->hand_stand_collection_; }
	MuzHandStandCollectionModel& get_hand_stand_collection() { return this->hand_stand_collection_; }


};
