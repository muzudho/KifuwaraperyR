#include "../src/muz_game_engine_service.hpp"
#include "../src/lib_gui/muz_engine_settings_initialize_service.hpp"


using namespace std;



// ========================================
// 生成／破棄
// ========================================


/// <summary>
/// 生成
/// </summary>
MuzGameEngineService::MuzGameEngineService()
{
    this->m_pGameEngineStore = std::unique_ptr<MuzGameEngineStorageModel>(new MuzGameEngineStorageModel);
}


/// <summary>
/// 破棄。
/// </summary>
MuzGameEngineService::~MuzGameEngineService()
{
    this->m_pGameEngineStore.reset();
}


// ========================================
// ライフサイクルメソッド
// ========================================


/// <summary>
/// 最初の設定
/// </summary>
void MuzGameEngineService::initialize_10a()
{
    cout << "[game_engine] initialize." << endl;


    cout << "(^q^) 2.9 . エンジン設定！" << endl;
    MuzEngineSettingsInitializeService engineSettingsInitialize;
    engineSettingsInitialize.initialize_10a510b_engineOptions(
        594,    // TODO: Move::m_MAX_LEGAL_MOVES,
        32601,  // TODO: SweetnessInfinite,
        32600,  // TODO: SweetnessMate0Ply,
        64,     // TODO: g_MaxThreads,
        &this->m_pGameEngineStore->m_engineSettings,
        // onHashSizeChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->m_pGameEngineStore.get()->m_tt.setSize(opt);
        },
        // onHashCleared:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->m_pGameEngineStore.get()->m_tt.Clear();
        },
        // onEvalDirChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: std::unique_ptr<KkKkpKppStorage1>(new KkKkpKppStorage1)->initialize_10a600b(opt, true);
        },
        // onMaxThreadsPerSplitPointChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->m_pGameEngineStore.get()->m_pub.ReadUSIOptions(this->m_pGameEngineStore.get());
        },
        // onThreadsChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->m_pGameEngineStore.get()->m_pub.ReadUSIOptions(this->m_pGameEngineStore.get());
        },
        // getCpuCoreCount:
        []()    // [this]()
        {
            // 論理的なコア数の取得
            // todo: boost::thread::physical_concurrency() を使うこと。
            // std::thread::hardware_concurrency() は 0 を返す可能性がある。
            // 
            // TODO: return std::max(static_cast<int>(std::thread::hardware_concurrency() / 2), 1);
            return 1;   // とりあえず1で固定
        });
}


/// <summary>
/// 本体
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
void MuzGameEngineService::main_loop_50a(int argc, char* argv[])
{
    cout << "[game_engine] main loop." << endl;
}


/// <summary>
/// 事後処理
/// </summary>
void MuzGameEngineService::finalize_90a()
{
    cout << "[game_engine] finalize." << endl;
}
