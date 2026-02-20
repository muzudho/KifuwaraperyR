//
// 📄 持ち駒
//

#pragma once

#include "piece_type.hpp"
#include <string>

/// <summary>
/// 持ち駒を表すときに使用する。
/// todo: HGold を HRook の後ろに持っていき、PieceType との変換を簡単に出来るようにする。
/// </summary>
enum HandPiece
{
	/// <summary>
	/// 持ち駒の歩
	/// </summary>
	HPawn,

	/// <summary>
	/// 持ち駒の香
	/// </summary>
	HLance,
	
	/// <summary>
	/// 持ち駒の桂馬
	/// </summary>
	HKnight,
	
	/// <summary>
	/// 持ち駒の銀
	/// </summary>
	HSilver,
	
	/// <summary>
	/// 持ち駒の金
	/// </summary>
	HGold,
	
	/// <summary>
	/// 持ち駒の角
	/// </summary>
	HBishop,
	
	/// <summary>
	/// 持ち駒の飛車
	/// </summary>
	HRook,
	
	/// <summary>
	/// 列挙型の終端
	/// </summary>
	HandPieceNum
};

/// <summary>
/// 
/// </summary>
extern const HandPiece g_PIECETYPE_TO_HANDPIECE_TABLE[g_PIECETYPE_NUM];


namespace {


	//────────────────────────────────────────────────────────────────────────────────
	// 非クラスメンバ 静的グローバル・オブジェクト
	//────────────────────────────────────────────────────────────────────────────────


	/// <summary>
	/// USI用持ち駒。２文字。
	/// </summary>
	static const std::string g_CONV_HAND_PIECE_2LEN_STRING_TABLE[HandPiece::HandPieceNum] = {
		"P*", "L*", "N*", "S*", "G*", "B*", "R*"
	};

	/// <summary>
	/// 
	/// </summary>
	static const char g_CONV_HAND_PIECE_1CHAR_TABLE[HandPiece::HandPieceNum] = {
		'P', 'L', 'N', 'S', 'G', 'B', 'R'
	};
}


/// <summary>
/// 持ち駒の操作
/// </summary>
class ConvHandPiece {


public:


	/// <summary>
	/// 暗算表を使うぜ☆（＾ｑ＾）
	/// </summary>
	/// <param name="hp"></param>
	/// <returns></returns>
	static inline std::string GET_2CHARS_STRING(const HandPiece hp) {
		return g_CONV_HAND_PIECE_2LEN_STRING_TABLE[hp];
	}


	/// <summary>
	/// 暗算表を使うぜ☆（＾ｑ＾）
	/// </summary>
	/// <param name="pt"></param>
	/// <returns></returns>
	static inline HandPiece FromPieceType(const PieceType pt) {
		return g_PIECETYPE_TO_HANDPIECE_TABLE[pt];
	}
};
