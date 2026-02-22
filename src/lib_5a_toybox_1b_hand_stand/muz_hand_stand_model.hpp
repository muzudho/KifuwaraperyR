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
struct MuzHandStandStruct {
	unsigned int fu_ : 5;		// 歩   0-18
	unsigned int kyo_ : 3;		// 香   0-4
	unsigned int kei_ : 3;		// 桂   0-4
	unsigned int gin_ : 3;		// 銀   0-4
	unsigned int kin_ : 3;		// 金   0-4
	unsigned int kaku_ : 2;		// 角   0-2
	unsigned int hi_ : 2;		// 飛   0-2
};

/// <summary>
///		<pre>
/// 駒台（持ち駒）
///		</pre>
/// </summary>
class MuzHandStandModel
{


public:


	// ========================================
	// 生成／破棄
	// ========================================


	/// <summary>
	/// 
	/// </summary>
	MuzHandStandModel() {}


	/// <summary>
	/// 
	/// </summary>
	/// <param name="v"></param>
	explicit MuzHandStandModel(u32 v) : m_value_(v) {}


	// ========================================
	// フィールド
	// ========================================


private:


	static const int m_HandPieceShiftBits[HandPieceNum];

	/// <summary>
    /// 歩は 0～18 枚有るので、5ビットあれば足りる。
    /// 香は 0～4 枚有るので、3ビットあれば足りる。
    /// 桂は 0～4 枚有るので、3ビットあれば足りる。
    /// 銀は 0～4 枚有るので、3ビットあれば足りる。
	/// 金は 0～4 枚有るので、3ビットあれば足りる。
	/// 角は 0～2 枚有るので、2ビットあれば足りる。
    /// 飛は 0～2 枚有るので、2ビットあれば足りる。
	/// </summary>
	static const int m_HPawnShiftBits = 0;
	static const int m_HLanceShiftBits = 6;
	static const int m_HKnightShiftBits = 10;
	static const int m_HSilverShiftBits = 14;
	static const int m_HGoldShiftBits = 18;
	static const int m_HBishopShiftBits = 22;
	static const int m_HRookShiftBits = 25;


protected:



	/// <summary>
	/// 
	/// </summary>
	u32 m_value_;


public:
	// ========================================
	// アクセッサー
	// ========================================


	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	u32 Value() const;


	// ========================================
	// 主要メソッド
	// ========================================


	/// <summary>
	/// num が int だけどまあ良いか。
	/// </summary>
	/// <param name="num"></param>
	/// <param name="handPiece"></param>
	void OrEqual(const int num, const HandPiece handPiece);
};
