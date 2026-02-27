#include "muz_board_model.hpp"
#include <cctype>   // これだけで std::isdigit(int ch) が使える


// ========================================
// アクセッサ
// ========================================


/// <summary>
/// マスにある駒を取得
/// </summary>
/// <param name="sq">マス番号</param>
/// <returns></returns>
const Piece MuzBoardModel::get_piece(const Square sq) const
{
	return this->piece_[sq];
}


/// <summary>
/// マスに駒を置く。
/// </summary>
void MuzBoardModel::set_piece(const Square sq, const Piece piece)
{
	this->piece_[sq] = piece;
}


// ========================================
// 主要メソッド
// ========================================


bool MuzBoardModel::from_string(std::string_view board_str)
{
	Square sq = A9;               // 仮の初期位置
	Piece promote = Piece::UnPromoted;

	for (char ch : board_str)
	{
		if (std::isdigit(ch))
		{
			sq = static_cast<Square>(
				static_cast<int>(sq) +
				static_cast<int>(SquareDelta::DeltaE) * (ch - '0')
				);
		}
		else if (ch == '/')
		{
			sq = static_cast<Square>(
				static_cast<int>(sq) +
				static_cast<int>(SquareDelta::DeltaW) * 9 +
				static_cast<int>(SquareDelta::DeltaS)
				);
		}
		else if (ch == '+')
		{
			promote = Piece::Promoted;
		}
		else if (g_charToPieceUSI.IsLegalChar(ch))
		{
			if (!ConvSquare::CONTAINS_OF10(sq)) return false;

			Piece p = (Piece)(g_charToPieceUSI.GetValue(ch) + promote);
			this->set_piece(sq, p);

			promote = Piece::UnPromoted;

			sq = static_cast<Square>(
				static_cast<int>(sq) +
				static_cast<int>(SquareDelta::DeltaE)
				);
		}
		else
		{
			return false;
		}
	}
	return true;
}
