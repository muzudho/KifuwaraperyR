#include "muz_position_n3_model.hpp"


// ========================================
// 主要メソッド
// ========================================


// 盤上の駒
bool MuzPositionN3Model::ParseBoard(std::string_view board_str)
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
			SetPiece(p, sq);

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


// 手番
bool MuzPositionN3Model::ParseTurn(std::string_view turn_str)
{
	if (turn_str == "b") { m_turn_ = Color::Black; return true; }
	if (turn_str == "w") { m_turn_ = Color::White; return true; }
	return false;
}


// 持ち駒
bool MuzPositionN3Model::ParseHand(std::string_view hand_str)
{
    // 持ち駒がない場合は "-" で表す
	if (hand_str == "-")
	{
		std::fill(std::begin(m_hand_models_), std::end(m_hand_models_), 0);
		return true;
	}

	std::size_t count = 0;

	for (char ch : hand_str)
	{
        // 数字が続く場合は、次の駒の枚数を表す
		if (std::isdigit(ch))
		{
			count = count * 10 + (ch - '0');
		}
        // 駒の種類を表す文字が来たら、枚数をセットして、カウントをリセット
		else if (g_charToPieceUSI.IsLegalChar(ch))
		{
			Piece piece = g_charToPieceUSI.GetValue(ch);
			SetHand(piece, count == 0 ? 1 : count);
			count = 0;
		}
		else
		{
			return false;
		}
	}

	// 最後に残った数字は無視しない（エラー扱い可）
	return count == 0;
}


// 次の手が何手目か
int MuzPositionN3Model::ParsePly(std::string_view ply_str)
{
	// 空 or 空白だけ → 即失敗
	if (ply_str.empty()) return -1;

	int value = 0;  // 初期化しておく（安全のため）

	// この部分が C++17〜 で導入された高速整数パース
	auto [ptr, ec] = std::from_chars(
		ply_str.data(),
		ply_str.data() + ply_str.size(),
		value
	);

	// 1. パース失敗（数字が1つもなかった）
	// 2. 全部消費されてない（末尾にゴミがついてる）
	// → 両方チェックするのがベストプラクティス
	if (ec != std::errc{} || ptr != ply_str.data() + ply_str.size()) return -1;

	// ここまで来たら value は有効な整数
	// 手数として負数は普通おかしいので弾くのもアリ
	if (value <= 0) return -1;

	// 元のロジックを再現（1手目を2とかにするやつ）
	// ※ 2*(n-1) + (自分が白なら1) という形が多い
	return std::max(2 * (value - 1), 0) + static_cast<int>(m_turn_ == Color::White);
}
