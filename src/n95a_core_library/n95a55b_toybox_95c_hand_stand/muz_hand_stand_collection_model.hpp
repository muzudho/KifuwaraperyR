#pragma once

#include "muz_hand_stand_model.hpp"
#include <string_view>
#include <optional>
#include <tuple>

/// <summary>
/// 駒台２つをまとめて表すぜ（＾～＾） SFEN 形式がそうなってるから（＾～＾）
/// </summary>
class MuzHandStandCollectionModel
{


	// ========================================
	// フィールド
	// ========================================


private:
	/// <summary>
	/// 先後対局者別の手駒
	/// </summary>
	MuzHandStandModel m_hand_stands_[g_COLOR_NUM];


	// ========================================
	// アクセッサ
	// ========================================


public:
	/// <summary>
	/// 持ち駒
	/// </summary>
	/// <typeparam name="CLR"></typeparam>
	/// <returns></returns>
	template<Color CLR>
	MuzHandStandModel GetHandStand() const
	{
		return this->m_hand_stands_[CLR];
	}
	MuzHandStandModel GetHandStand(const Color c) const;


	// ========================================
	// 主要メソッド
	// ========================================


	/// <summary>
	///		<pre>
	///	駒台（持ち駒）のセットをテキスト形式で行う。
	///		- 例えば "2P1R" なら、▲歩が2、▲飛が1枚あることを表す。
	///		</pre>
	/// </summary>
	static std::optional<std::pair<MuzHandStandModel, MuzHandStandModel>> parse(
		std::string_view hand_str);


	/// <summary>
	///		<pre>
	///	駒台（持ち駒）のセットをテキスト形式で行う。
	///		- 例えば "2P1R" なら、▲歩が2、▲飛が1枚あることを表す。
	///		</pre>
	/// </summary>
	static bool parse_hand_stand_collection(
		std::string_view hand_str,
		MuzHandStandModel& blackHandStand,
		MuzHandStandModel& whiteHandStand);
};
