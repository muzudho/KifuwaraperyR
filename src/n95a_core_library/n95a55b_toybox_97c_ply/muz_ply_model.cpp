#include "muz_ply_model.hpp"


// ========================================
// 主要メソッド
// ========================================


// 次の手が何手目か。エラーのときは -1 を返す。
bool MuzPlyModel::from_string(std::string_view ply_str)
{
	// 空 or 空白だけ → 即失敗
	if (ply_str.empty()) return false;

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
	if (value <= 0) return false;

	// 元のロジックを再現（1手目を2とかにするやつ）
	// ※ 2*(n-1) + (自分が白なら1) という形が多い
	this->ply_ = std::max(2 * (value - 1), 0) + static_cast<int>(turn_.is_white());
	return true;
}
