#pragma once

#include "../n95a_core_library/lib_5a_gui/muz_engine_settings_model.hpp"
#include "../n95a_core_library/n95a55b_toybox_85c_position/muz_position_model.hpp"
#include "../n95a_core_library/n95a55b_toybox_95c_hand_stand/muz_hand_stand_model.hpp"

/// <summary>
///		<pre>
/// ゲームエンジン倉庫
/// 
///		- ゲームエンジンが１つだけ持つ
///		- 複数の探索スレッドに渡される
///		</pre>
/// </summary>
class MuzGameEngineStorageModel
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
    MuzPositionModel position_;
    /// <summary>
	/// TODO: ［駒台］は［ポジション］クラスに移動したい（＾～＾）
	/// </summary>
	MuzHandStandModel black_hand_stand_;
	MuzHandStandModel white_hand_stand_;


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
	const MuzPositionModel& get_position() const;
	MuzPositionModel& get_position();
};
