//
// 📄 局面の状態を表すクラス
//
#include "muz_position_base_model.hpp"


// ========================================
// アクセッサ
// ========================================


void MuzPositionBaseModel::SetPiece(const Piece piece, const Square sq)
{
    MuzPositionN1Model::SetPiece(piece, sq);
	const Color c = ConvPiece::TO_COLOR10(piece);
	const PieceType pt = ConvPiece::TO_PIECE_TYPE10(piece);

	// TODO: 駒の配置を表すビットボードを更新
	//g_setMaskBb.AddBit(&this->m_BB_ByPiecetype_[pt], sq);
	//g_setMaskBb.AddBit(&this->m_BB_ByColor_[c], sq);
	//g_setMaskBb.AddBit(&this->m_BB_ByPiecetype_[PieceType::N00_Occupied], sq);
}


// ========================================
// 主要メソッド
// ========================================
