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


public:


	// ========================================
	// フィールド
	// ========================================


	/// <summary>
	/// USIエンジン設定
	/// </summary>
	MuzEngineSettingsModel	m_engineSettings;


};

