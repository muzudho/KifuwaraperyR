//
// 📄 局面の状態を表すクラス
//
#include "muz_position_base_model.hpp"


// ========================================
// アクセッサ
// ========================================


/// <summary>
/// 何手目か
/// </summary>
/// <returns></returns>
Ply MuzPositionBaseModel::GetGamePly() const
{
	return this->m_gamePly_;
}


/// <summary>
/// 
/// </summary>
/// <param name="ply"></param>
void MuzPositionBaseModel::SetStartPosPly(const Ply ply)
{
	this->m_gamePly_ = ply;
}


/// <summary>
/// 手番を取得
/// </summary>
/// <returns></returns>
Color MuzPositionBaseModel::GetTurn() const
{
	return this->m_turn_;
}


/// <summary>
/// 
/// </summary>
/// <param name="sq"></param>
/// <returns></returns>
Piece MuzPositionBaseModel::GetPiece(const Square sq) const
{
	return this->m_piece_[sq];
}


void MuzPositionBaseModel::SetPiece(const Piece piece, const Square sq)
{
	const Color c = ConvPiece::TO_COLOR10(piece);
	const PieceType pt = ConvPiece::TO_PIECE_TYPE10(piece);

	this->m_piece_[sq] = piece;

    // TODO: 駒の配置を表すビットボードを更新
	//g_setMaskBb.AddBit(&this->m_BB_ByPiecetype_[pt], sq);
	//g_setMaskBb.AddBit(&this->m_BB_ByColor_[c], sq);
	//g_setMaskBb.AddBit(&this->m_BB_ByPiecetype_[PieceType::N00_Occupied], sq);
}


/// <summary>
/// 
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
Hand MuzPositionBaseModel::GetHand(const Color c) const
{
	return this->m_hand_[c];
}


/// <summary>
/// 
/// </summary>
/// <param name="hp"></param>
/// <param name="c"></param>
/// <param name="num"></param>
void MuzPositionBaseModel::SetHand(const HandPiece hp, const Color c, const int num)
{
	this->m_hand_[c].OrEqual(num, hp);
}


/// <summary>
/// 
/// </summary>
/// <param name="piece"></param>
/// <param name="num"></param>
void MuzPositionBaseModel::SetHand(const Piece piece, const int num)
{
	const Color c = ConvPiece::TO_COLOR10(piece);
	const PieceType pt = ConvPiece::TO_PIECE_TYPE10(piece);
	const HandPiece hp = ConvHandPiece::FromPieceType(pt);
	this->SetHand(hp, c, num);
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


bool MuzPositionBaseModel::ParseBoard(std::string_view board_str)
{

	/*
	// 盤上の駒
	while (ss.get(token) && token != ' ') {
		if (isdigit(token)) {
			sq += SquareDelta::DeltaE * (token - '0');
		}
		else if (token == '/') {
			sq += (SquareDelta::DeltaW * 9) + SquareDelta::DeltaS;
		}
		else if (token == '+') {
			promoteFlag = Promoted;
		}
		else if (g_charToPieceUSI.IsLegalChar(token)) {
			if (ConvSquare::CONTAINS_OF10(sq)) {
				SetPiece(g_charToPieceUSI.GetValue(token) + promoteFlag, sq);
				promoteFlag = Piece::UnPromoted;
				sq += SquareDelta::DeltaE;
			}
			else {
				goto INCORRECT;
			}
		}
		else {
			goto INCORRECT;
		}
	}
	*/

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

			Piece p = g_charToPieceUSI.GetValue(ch) + promote;
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

bool MuzPositionBaseModel::ParseTurn(std::string_view turn_str)
{

	/*
	// 手番
	while (ss.get(token) && token != ' ')
	{
		if (token == 'b') {
			this->m_turn_ = Black;
		}
		else if (token == 'w') {
			this->m_turn_ = White;
		}
		else {
			goto INCORRECT;
		}
	}
	*/

	if (turn_str == "b") { m_turn_ = Color::Black; return true; }
	if (turn_str == "w") { m_turn_ = Color::White; return true; }
	return false;
}

bool MuzPositionBaseModel::ParseHand(std::string_view hand_str)
{

	/*
	// 持ち駒
	for (int digits = 0; ss.get(token) && token != ' '; ) {
		if (token == '-') {
			memset(m_hand_, 0, sizeof(m_hand_));
		}
		else if (isdigit(token)) {
			digits = digits * 10 + token - '0';
		}
		else if (g_charToPieceUSI.IsLegalChar(token)) {
			// 持ち駒を32bit に pack する
			const Piece piece = g_charToPieceUSI.GetValue(token);
			this->SetHand(piece, (digits == 0 ? 1 : digits));

			digits = 0;
		}
		else {
			goto fail;
		}
	}
	*/

	if (hand_str == "-")
	{
		std::fill(std::begin(m_hand_), std::end(m_hand_), 0);
		return true;
	}

	std::size_t count = 0;

	for (char ch : hand_str)
	{
		if (std::isdigit(ch))
		{
			count = count * 10 + (ch - '0');
		}
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

int MuzPositionBaseModel::ParsePly(std::string_view ply_str)
{

	/*
	// 次の手が何手目か
	ss >> this->m_gamePly_;
	this->m_gamePly_ = std::max(2 * (this->m_gamePly_ - 1), 0) + static_cast<int>(this->GetTurn() == White);
	*/

	int value{};
	auto [ptr, ec] = std::from_chars(ply_str.data(), ply_str.data() + ply_str.size(), value);

	if (ec != std::errc{} || ptr != ply_str.data() + ply_str.size())
		return -1;

	// 元のロジックを再現
	return std::max(2 * (value - 1), 0) + static_cast<int>(m_turn_ == Color::White);
}
