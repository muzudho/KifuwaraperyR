#pragma once
#include <iostream>
#include <memory> // 追加: unique_ptrのため
#include "../src/concept_game_engine/muz_game_engine_storage_model.hpp"


/// <summary>
/// 
/// </summary>
class MuzGameEngineService
{


public:


	// ========================================
	// 生成／破棄
	// ========================================


	MuzGameEngineService();
	~MuzGameEngineService();


	// ========================================
	// フィールド
	// ========================================


	/// <summary>
	///		ゲームエンジンが１つだけ持つ、局面の探索状態を保存するクラス☆（＾ｑ＾）
	/// </summary>
	std::unique_ptr<MuzGameEngineStorageModel> m_pGameEngineStore;


	// ========================================
	// ライフサイクルメソッド
	// ========================================


	void initialize_10a();
	void body_50a(int argc, char* argv[]);
	void finalize_90a();
};
