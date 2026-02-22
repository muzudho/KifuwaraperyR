#pragma once

#include "../lib_5a_toybox_n1/piece.hpp"
#include "../lib_5a_toybox_n1/square.hpp"

/// <summary>
///		<pre>
/// ボードの状態を表すぜ（＾～＾）
///     </pre>
/// </summary>
class MuzBoardModel
{


	// ========================================
	// フィールド
	// ========================================


private:
	/// <summary>
	/// 各マスの駒
	/// </summary>
	Piece piece_[SquareNum];


	// ========================================
	// アクセッサ
	// ========================================


public:


	/// <summary>
	/// 
	/// </summary>
	/// <param name="sq"></param>
	/// <returns></returns>
	Piece get_piece(const Square sq);

	void set_piece(const Piece piece, const Square sq);
};
