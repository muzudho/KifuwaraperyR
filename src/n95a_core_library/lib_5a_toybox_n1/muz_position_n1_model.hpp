#pragma once

// MuzPositionN1Model では使ってないヘッダーファイルでも、他のクラスが MuzPositionN1Model をインクルードすれば lib_5a_toybox_n1 のヘッダーファイルが全部付いてくるようにします。
#include "../n95a55b_toybox_85c_position/muz_position_model.hpp"
#include "../n95a55b_toybox_94c_board/muz_board_model.hpp"
#include "piece_type.hpp"

class MuzPositionN1Model
{


protected:


	// ========================================
    // 生成／破棄
	// ========================================


	MuzPositionN1Model();


	// ========================================
	// フィールド
	// ========================================


public:
	/// <summary>
	/// ボードの状態を表すぜ（＾～＾）
	/// </summary>
	MuzPositionModel position_;


protected:


	// ========================================
	// アクセッサ
	// ========================================


	/// <summary>
	/// 
	/// </summary>
	/// <param name="ply"></param>
	void SetStartPosRadixHalfPly(const RadixHalfPly radix_half_ply);


	/// <summary>
	/// ［将棋式の手数、つまり開始局面を０とする］を取得。
	/// </summary>
	/// <returns></returns>
	RadixHalfPly GetRadixHalfPly();


	/// <summary>
	/// 次の手番
	/// </summary>
	/// <returns></returns>
	Color GetTurn();
};