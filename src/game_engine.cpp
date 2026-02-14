#include "../src/game_engine.hpp"

using namespace std;



// ========================================
// 生成／破棄
// ========================================


/// <summary>
/// 生成
/// </summary>
GameEngineShogi::GameEngineShogi()
{
    this->m_ourCarriage = std::unique_ptr<GameEngineStorageOurCarriage>(new GameEngineStorageOurCarriage);
}


/// <summary>
/// 破棄。
/// </summary>
GameEngineShogi::~GameEngineShogi()
{
    this->m_ourCarriage.reset();
}


// ========================================
// ライフサイクルメソッド
// ========================================


/// <summary>
/// 最初の設定
/// </summary>
void GameEngineShogi::initialize_10a()
{
    cout << "[game_engine] initialize." << endl;
}


/// <summary>
/// 本体
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
void GameEngineShogi::body_50a(int argc, char* argv[])
{
    cout << "[game_engine] body." << endl;
}


/// <summary>
/// 事後処理
/// </summary>
void GameEngineShogi::finalize_90a()
{
    cout << "[game_engine] finalize." << endl;
}
