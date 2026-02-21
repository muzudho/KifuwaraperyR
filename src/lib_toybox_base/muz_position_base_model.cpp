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


/// <summary>
///		<pre>
/// 局面をセットします。
/// sfen 形式の文字列を解析して、盤上の駒の配置、手番、持ち駒、次の手数などを Position クラスのメンバ変数に設定します。
/// また、ゲームエンジンのストレージモデルもセットします。
/// 解析に失敗した場合はエラーメッセージを出力します。
///		</pre>
/// </summary>
/// <param name="sfen"></param>
void MuzPositionBaseModel::Set(std::string_view sfen)
{
	//Piece promoteFlag = UnPromoted;
	//std::istringstream ss(sfen);
	//char token;
	//Square sq = A9;

	//MuzGameEngineStorageModel* s = std::move(m_pGameEngineStore_);

	//this->Clear();

	//this->SetGameEngineStore(s);

    // コマンドをスペースで分割して、std::views::split と std::views::transform を使って、std::string_view の range を作る。
	auto parts = sfen
		| std::views::split(' ')
		| std::views::transform([](auto&& r)
			{
				return std::string_view(&*r.begin(), std::ranges::distance(r));
			});

	auto it = parts.begin();

	// 1. 盤面部分
	if (it == parts.end()) goto fail;
	if (!ParseBoard(*it)) goto fail;
	++it;

	// 2. 手番
	if (it == parts.end()) goto fail;
	if (!ParseTurn(*it)) goto fail;
	++it;

	// 3. 持ち駒
	if (it == parts.end()) goto fail;
	if (!ParseHand(*it)) goto fail;
	++it;

	// 4. 手数（オプション）
	if (it != parts.end())
	{
		if (auto ply = ParsePly(*it))
			m_gamePly_ = *ply;
		else
			goto fail;
	}

	return;

fail:
	std::cout << "incorrect SFEN string : " << sfen << "\n";
}
