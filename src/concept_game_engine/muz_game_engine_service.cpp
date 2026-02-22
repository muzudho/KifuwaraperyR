#include "../lib_5a_gui/muz_engine_settings_initialize_service.hpp"
#include "../lib_1a2b_cli/muz_cli_service.hpp"
#include "../lib_1a_cpp/muz_string_service.hpp"
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
    this->gameEngineStore_ = std::unique_ptr<MuzGameEngineStorageModel>(new MuzGameEngineStorageModel);
}


/// <summary>
/// 破棄。
/// </summary>
MuzGameEngineService::~MuzGameEngineService()
{
    this->gameEngineStore_.reset();
}


// ========================================
// プロパティー
// ========================================


// 将棋エンジン表示名
#ifdef NDEBUG
const std::string my_name_ = "KifuwaraperyR(from Apery_Twig_SDT3)";
#else
const std::string my_name_ = "KifuwaraperyR(from Apery_Twig_SDT3) Debug Build";
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
        &this->gameEngineStore_->m_engineSettings,
        // onHashSizeChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->gameEngineStore_.get()->m_tt.setSize(opt);
        },
        // onHashCleared:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->gameEngineStore_.get()->m_tt.Clear();
        },
        // onEvalDirChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: std::unique_ptr<KkKkpKppStorage1>(new KkKkpKppStorage1)->initialize_10a600b(opt, true);
        },
        // onMaxThreadsPerSplitPointChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->gameEngineStore_.get()->m_pub.ReadUSIOptions(this->gameEngineStore_.get());
        },
        // onThreadsChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->gameEngineStore_.get()->m_pub.ReadUSIOptions(this->gameEngineStore_.get());
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

    // TODO: ここで実際のコマンド処理を書く
    cliSvc.set_process_command_line([this](const std::string& line)
        {
            if (!this->gameEngineStore_->is_usi()) {
                std::cout << "処理するよ: " << line << "\n";
            }

            MuzStringService stringSvc;
            std::vector<std::string> tokens;

            // 半角スペース ' ' で分割
            tokens = stringSvc.split_command_line(line);


            MuzCliResultModel result;

            // ポンダー（相手の手番に思考すること）してるのを止めるか
            bool shall_stop_ponder = false;

            // TODO: 対局中に呼び出される回数が多いものを先にした方がいいかだぜ（＾～＾）？
            // 例: 終了したいなら
            if (line == "quit")
            {
                // ここで何かフラグを立てて main_loop から抜けるようにする
                // または throw とか exit(0) でもいいけど、できれば綺麗に抜けたい
                result.request_quit();
                
                // 終了時にポンダーヒットが来ることがあるので、対処してください。
                shall_stop_ponder = true;   // ポンダーしてようと、してなかろうと、止めたらいい。
            }
            else if (line == "usi")
            {
                this->gameEngineStore_->set_usi();

                // USIプロトコルのバージョンを返す。
                std::cout << "id name " << my_name_ << "\nid author (Derivation)Takahashi Satoshi (Base)Hiraoka Takuya\nusiok" << "\n";

                // TODO: セット・オプション付けてください： std::cout << "id name " << my_name_ << "\nid author (Derivation)Takahashi Satoshi (Base)Hiraoka Takuya\n" << gameEngineStore_.m_engineSettings << "\nusiok" << "\n";
            }
            else if (line == "isready")
            {
                // エンジンが準備できたら、"readyok" を返す。
                std::cout << "readyok" << "\n";
            }
            else if (line == "setoption")
            {
                // TODO: エンジンのオプションを設定するコマンド。これが来たら、オプションを変更する。
                //gameEngineStore_.SetOption(ssCmd);
            }
            else if (line == "usinewgame")
            {
                //                // 新しいゲームの開始を知らせるコマンド。これが来たら、前のゲームの情報をクリアする。
                //                gameEngineStore_.m_tt.Clear();
                //
                //#if defined INANIWA_SHIFT
                //                inaniwaFlag = NotInaniwa;
                //#endif
                //#if defined BISHOP_IN_DANGER
                //                bishopInDangerFlag = NotBishopInDanger;
                //#endif
                //
                //                // 最初は乱数に偏りがあるかも。少し回しておく。
                //                for (int i = 0; i < 100; ++i)
                //                {
                //                    g_randomTimeSeed();
                //                }
            }
            else if (line == "position")
            {
                // TODO: 局面を設定するコマンド。これが来たら、局面を変更する。
                //usiOperation.SetPosition(pos, ssCmd);
            }
            else if (tokens[0] == "go")
            {
                //// TODO: 思考開始のコマンド。これが来たら、思考を開始する。
                //usiOperation.Go(gameStats, pos, ssCmd);

                std::cout << "bestmove resign" << "\n";  // とりあえず投了を返すぜ（＾ｑ＾）
            }
            // ----------------------------------------
            // 以下、独自実装
            // ----------------------------------------
            else if (tokens[0] == "handb")
            {
                // TODO: 先手駒台の描画
            }
            else if (tokens[0] == "handw")
            {
                // TODO: 後手駒台の描画
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
