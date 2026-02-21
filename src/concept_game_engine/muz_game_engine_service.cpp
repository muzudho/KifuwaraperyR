#include "../lib_5a_gui/muz_engine_settings_initialize_service.hpp"
#include "../lib_1a2b_cli/muz_cli_service.hpp"
#include "muz_game_engine_service.hpp"


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
// プロパティー
// ========================================


// 将棋エンジン表示名
#ifdef NDEBUG
const std::string MyName = "Kifuwarapery(Apery_Twig_SDT3)";
#else
const std::string MyName = "Kifuwarapery(Apery) Debug Build";
#endif


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


#if !defined MINIMUL

/*
/// <summary>
///		<pre>
/// for debug
/// 指し手生成の速度を計測
///		</pre>
/// </summary>
/// <param name="pos"></param>
void measureGenerateMoves(const Position& pos) {
    pos.Print();

    MoveStack legalMoves[Move::m_MAX_LEGAL_MOVES];
    for (int i = 0; i < Move::m_MAX_LEGAL_MOVES; ++i)
    {
        legalMoves[i].m_move = g_MOVE_NONE;
    }
    MoveStack* pms = &legalMoves[0];
    const u64 num = 5000000;
    Stopwatch t = Stopwatch::CreateStopwatchByCurrentTime();
    if (pos.inCheck()) {
        for (u64 i = 0; i < num; ++i) {
            pms = &legalMoves[0];
            pms = g_moveGenerator200.GenerateMoves_2(N06_Evasion, pms, pos);
        }
    }
    else {
        for (u64 i = 0; i < num; ++i) {
            pms = &legalMoves[0];
            pms = g_moveGenerator200.GenerateMoves_2(N03_CapturePlusPro, pms, pos);
            pms = g_moveGenerator200.GenerateMoves_2(N04_NonCaptureMinusPro, pms, pos);
            pms = g_moveGenerator200.GenerateMoves_2(N02_Drop, pms, pos);
            //			pms = generateMoves<PseudoLegal>(pms, pos);
            //			pms = generateMoves<Legal>(pms, pos);
        }
    }
    const int elapsed = t.GetElapsed();
    std::cout << "elapsed = " << elapsed << " [msec]" << std::endl;
    if (elapsed != 0) {
        std::cout << "times/s = " << num * 1000 / elapsed << " [times/sec]" << std::endl;
    }
    const ptrdiff_t count = pms - &legalMoves[0];
    std::cout << "num of moves = " << count << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << legalMoves[i].m_move.ToCSA() << ", ";
    }
    std::cout << std::endl;
}
*/

#endif


/// <summary>
/// 本体
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
void MuzGameEngineService::main_loop_50a(int argc, char* argv[])
{

    MuzCliService cliSvc;

    cliSvc.set_process_command([](const std::string& cmd)
        {
            // TODO: ここで実際のコマンド処理を書く
            std::cout << "処理したよ: " << cmd << "\n";

            MuzCliResultModel result;

            // ポンダー（相手の手番に思考すること）してるのを止めるか
            bool shall_stop_ponder = false;

            // 例: 終了したいなら
            if (cmd == "quit")
            {
                // ここで何かフラグを立てて main_loop から抜けるようにする
                // または throw とか exit(0) でもいいけど、できれば綺麗に抜けたい
                result.request_quit();
                
                // 終了時にポンダーヒットが来ることがあるので、対処してください。
                shall_stop_ponder = true;   // ポンダーしてようと、してなかろうと、止めたらいい。
            }

            if (shall_stop_ponder)
            {
                // TODO: ポンダーを止める処理をここに書いてください。
            }

            return result;
        });

    // メインループを走らせます。
    cliSvc.main_loop(argc, argv);
}


/// <summary>
/// 事後処理
/// </summary>
void MuzGameEngineService::finalize_90a()
{
    cout << "[game_engine] finalize." << endl;
}
