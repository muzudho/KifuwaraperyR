#pragma once
#include <iostream>
#include <memory> // 追加: unique_ptrのため
#include "../src/game_engine_layer/game_engine_storage.hpp"


/// <summary>
/// 
/// </summary>
class GameEngineShogi {

public:

	/// <summary>
	///		ゲームエンジンが１つだけ持つ、局面の探索状態を保存するクラス☆（＾ｑ＾）
	/// </summary>
	std::unique_ptr<GameEngineStorageOurCarriage> m_ourCarriage;

public:
	GameEngineShogi();
	~GameEngineShogi();
	void initialize_10a();
	void body_50a(int argc, char* argv[]);
	void finalize_90a();
};
