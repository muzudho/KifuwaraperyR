#pragma once

#include "../n95a_core_library/n95a87b_stationaly_position/n95a87b63c_position/muz_stationaly_position_model.hpp"

/// <summary>
///		<pre>
/// ゲームエンジン倉庫
/// 
///		- ゲームエンジンが１つだけ持つ
///		- 複数の探索スレッドに渡される
///		</pre>
/// </summary>
class IMuzGameEngineStorageModel
{


	// ========================================
	// アクセッサー
	// ========================================


public:
	/// <summary>
	/// USIモードに入ったか。
	/// </summary>
	virtual bool is_usi() const = 0;
	virtual void set_usi() = 0;


	/// <summary>
	/// USIエンジン設定。
	/// </summary>
	/// <returns></returns>
	virtual const MuzEngineSettingsModel& get_engine_settings() const = 0;
	virtual MuzEngineSettingsModel& get_engine_settings() = 0;


	/// <summary>
	/// 盤。
	/// </summary>
	/// <returns></returns>
	virtual const MuzStationalyPositionModel& get_position() const = 0;
	virtual MuzStationalyPositionModel& get_position() = 0;
};
