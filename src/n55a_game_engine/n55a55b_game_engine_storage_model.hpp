#pragma once

#include "../n95a_core_library/lib_5a_gui/muz_engine_settings_model.hpp"
#include "../n95a_core_library/n95a87b_stationaly_position/n95a87b63c_position/muz_stationaly_position_model.hpp"
#include "../n95a_core_library/n95a87b_stationaly_position/n95a87b71c_hand_stand/muz_hand_stand_model.hpp"
#include "../interfaces/n55a55b_i_game_engine_storage_model.hpp"

/// <summary>
///		<pre>
/// ゲームエンジン倉庫
/// 
///		- ゲームエンジンが１つだけ持つ
///		- 複数の探索スレッドに渡される
///		</pre>
/// </summary>
class MuzGameEngineStorageModel : public IMuzGameEngineStorageModel
{


	// ========================================
	// 生成／破棄
	// ========================================

public:
	MuzGameEngineStorageModel();


	// ========================================
	// フィールド
	// ========================================


private:
	/// <summary>
	/// USIモードに入ったか。
	/// </summary>
	bool is_usi_;

public:

	/// <summary>
	/// USIエンジン設定
	/// </summary>
	MuzEngineSettingsModel	m_engineSettings;


    /// <summary>
    /// 局面（＾～＾）
    /// </summary>
    MuzStationalyPositionModel position_;


	// ========================================
	// アクセッサー
	// ========================================


	/// <summary>
	/// USIモードに入ったか。
	/// </summary>
	bool is_usi() const;
	void set_usi();


	/// <summary>
	/// 盤。
	/// </summary>
	/// <returns></returns>
	const MuzStationalyPositionModel& get_position() const;
	MuzStationalyPositionModel& get_position();
};
