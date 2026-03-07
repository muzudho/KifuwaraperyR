#pragma once

#include "../n95a83b_transpositional_position/muz_transpositional_position_model.hpp"

/// <summary>
///     <pre>
/// リュックサック。
/// 
///     - 設定にアクセスできるぜ（＾～＾）
///     - 局面が入ってるぜ（＾～＾）
///     </pre>
/// </summary>
class MuzRucksackModel
{


	// ========================================
	// フィールド
	// ========================================

private:
	/// <summary>
	/// 可動局面だぜ（＾～＾）
	/// </summary>
	MuzTranspositionalPositionModel transpositional_position_;


	// ========================================
	// アクセッサー
	// ========================================


public:
	/// <summary>
	/// 可動局面。
	/// </summary>
	/// <returns></returns>
	const MuzTranspositionalPositionModel& get_transpositonal_position() const;
	MuzTranspositionalPositionModel& get_transpositonal_position();
};
