//
// 📄 局面の状態を表すクラス
//
#include "muz_position_n1_model.hpp"


// ========================================
// 生成／破棄
// ========================================


MuzPositionN1Model::MuzPositionN1Model()
{
	// 盤上を空っぽにするぜ（＾～＾）
    this->board_ = MuzBoardModel{};
}


// ========================================
// アクセッサ
// ========================================


/// <summary>
/// 
/// </summary>
/// <param name="ply"></param>
void MuzPositionN1Model::SetStartPosPly(const Ply ply)
{
	this->m_gamePly_ = ply;
}


/// <summary>
/// 何手目か
/// </summary>
/// <returns></returns>
Ply MuzPositionN1Model::GetGamePly()
{
	return this->m_gamePly_;
}


/// <summary>
/// 手番を取得
/// </summary>
/// <returns></returns>
Color MuzPositionN1Model::GetTurn()
{
	return this->m_turn_;
}


/// <summary>
/// マスにある駒を取得
/// </summary>
/// <param name="sq">マス番号</param>
/// <returns></returns>
Piece MuzPositionN1Model::GetPiece(const Square sq)
{
	return this->m_piece_[sq];
}


/// <summary>
/// マスに駒を置く。
/// </summary>
void MuzPositionN1Model::SetPiece(const Piece piece, const Square sq)
{
	this->m_piece_[sq] = piece;
}
