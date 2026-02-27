#pragma once

#include <iostream>
#include <memory> // 追加: unique_ptrのため
#include "n55a55b_game_engine_storage_model.hpp"

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
	///	ゲームエンジン倉庫☆（＾ｑ＾）
	///
	///    - ゲームエンジンが１つだけ持つ、局面の探索状態を保存するクラス☆（＾ｑ＾）
	/// </summary>
	std::unique_ptr<MuzGameEngineStorageModel> gameEngineStore_;


	// ========================================
	// ライフサイクルメソッド
	// ========================================


	void initialize_10a();
	void main_loop_50a(int argc, char* argv[]);
	void finalize_90a();
};
