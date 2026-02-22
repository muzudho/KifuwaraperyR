#pragma once

#include "../lib_1a_cpp/muz_int.hpp"
#include "hand_piece.hpp"

/// <summary>
///		<pre>
/// 駒台
/// 
///		- 持ち駒の枚数を表す構造体
///		- 合計21bit、uint32_tに余裕で収まる。
///		- 使い方
///			CapturedPieces pieces{};
///			pieces.fu = 9;
///			pieces.kaku = 1;
///		</pre>
/// </summary>
class MuzHandStandModel
{


public:


	// ========================================
	// フィールド
	// ========================================


private:

	unsigned int fu_ : 5;		// 歩   0-18 枚
	unsigned int kyo_ : 3;		// 香   0-4
	unsigned int kei_ : 3;		// 桂   0-4
	unsigned int gin_ : 3;		// 銀   0-4
	unsigned int kin_ : 3;		// 金   0-4
	unsigned int kaku_ : 2;		// 角   0-2
	unsigned int hi_ : 2;		// 飛   0-2




	static const int m_HandPieceShiftBits[HandPieceNum];


public:
	// ========================================
	// アクセッサー
	// ========================================


	/// <summary>
	/// 駒の枚数
	/// </summary>
	/// <returns></returns>
    unsigned int get_count(const HandPiece handPiece) const;
	void set_count(const HandPiece handPiece, unsigned int count);
};
