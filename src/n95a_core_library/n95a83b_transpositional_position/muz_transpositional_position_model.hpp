#pragma once

#include "../n95a87b_stationaly_position/n95a87b63c_position/muz_stationaly_position_model.hpp"

/// <summary>
///     <pre>
/// 可動局面。
///     </pre>
/// </summary>
class MuzTranspositionalPositionModel
{
	// ========================================
	// フィールド
	// ========================================

private:
	/// <summary>
	/// 静止局面だぜ（＾～＾）
	/// </summary>
	MuzStationalyPositionModel stationaly_position_;


	// ========================================
	// アクセッサー
	// ========================================


public:
	/// <summary>
	/// 静止局面。
	/// </summary>
	/// <returns></returns>
	const MuzStationalyPositionModel& get_stationaly_position() const;
	MuzStationalyPositionModel& get_stationaly_position();
};
