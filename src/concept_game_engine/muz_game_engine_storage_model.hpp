#pragma once

#include "../lib_5a_gui/muz_engine_settings_model.hpp"

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


	// ========================================
	// アクセッサー
	// ========================================


	/// <summary>
	/// USIモードに入ったか。
	/// </summary>
	bool is_usi() const;
	void set_usi();
};
