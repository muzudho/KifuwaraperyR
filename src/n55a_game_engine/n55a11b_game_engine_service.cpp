#include "../n11a_views/n11a55b_toybox/n11a55b94c_board_view.hpp"
#include "../n11a_views/n11a55b_toybox/n11a55b95c_hand_stand_view.hpp"
#include "../n11a_views/n11a55b_toybox/n11a55b105c_turn_view.hpp"
#include "../n95a_core_library/lib_5a_gui/muz_engine_settings_initialize_service.hpp"
#include "../n95a_core_library/n95a55b_toybox_95c_hand_stand/muz_hand_stand_collection_model.hpp"
#include "../n95a_core_library/n95a55b_toybox_103c_ply/ply.hpp"
#include "../n95a_core_library/n95a55b_toybox_103c_ply/muz_ply_model.hpp"
#include "../n95a_core_library/n95a55b_toybox_105c_turn/color.hpp"
#include "../n95a_core_library/n95a95b_infrastructure_95c_cpp/muz_string_service.hpp"
#include "../n95a_core_library/n95a95b_infrastructure_94a_cli/muz_cli_service.hpp"
#include "n55a11b_game_engine_service.hpp"

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
    //cout << "(^q^) [n55a_game_engine] initialize." << endl;


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
    // テスト：駒台の初期化
    // TODO: これらの変数は、ポジションに移動したい（＾～＾）
    this->gameEngineStore_->black_hand_stand_.set_count(HRook, 0);
    this->gameEngineStore_->black_hand_stand_.set_count(HBishop, 1);
    this->gameEngineStore_->black_hand_stand_.set_count(HGold, 0);
    this->gameEngineStore_->black_hand_stand_.set_count(HSilver, 4);
    this->gameEngineStore_->black_hand_stand_.set_count(HKnight, 3);
    this->gameEngineStore_->black_hand_stand_.set_count(HLance, 1);
    this->gameEngineStore_->black_hand_stand_.set_count(HPawn, 2);   // とりあえず歩を２枚持ってることにするぜ（＾ｑ＾）

    this->gameEngineStore_->white_hand_stand_.set_count(HRook, 2);
    this->gameEngineStore_->white_hand_stand_.set_count(HBishop, 0);
    this->gameEngineStore_->white_hand_stand_.set_count(HGold, 1);
    this->gameEngineStore_->white_hand_stand_.set_count(HSilver, 0);
    this->gameEngineStore_->white_hand_stand_.set_count(HKnight, 1);
    this->gameEngineStore_->white_hand_stand_.set_count(HLance, 0);
    this->gameEngineStore_->white_hand_stand_.set_count(HPawn, 3);   // とりあえず歩を３枚持ってることにするぜ（＾ｑ＾）

    // テスト：盤の初期化
    // TODO: これらの変数は、ポジションに移動したい（＾～＾）
    this->gameEngineStore_->board_.set_piece(M91, WLance);
    this->gameEngineStore_->board_.set_piece(M81, WKnight);
    this->gameEngineStore_->board_.set_piece(M71, WSilver);
    this->gameEngineStore_->board_.set_piece(M61, WGold);
    this->gameEngineStore_->board_.set_piece(M51, WKing);
    this->gameEngineStore_->board_.set_piece(M41, WGold);
    this->gameEngineStore_->board_.set_piece(M31, WSilver);
    this->gameEngineStore_->board_.set_piece(M21, WKnight);
    this->gameEngineStore_->board_.set_piece(M11, WLance);
    this->gameEngineStore_->board_.set_piece(M82, WRook);
    this->gameEngineStore_->board_.set_piece(M22, WBishop);
    this->gameEngineStore_->board_.set_piece(M93, WPawn);
    this->gameEngineStore_->board_.set_piece(M83, WPawn);
    this->gameEngineStore_->board_.set_piece(M73, WPawn);
    this->gameEngineStore_->board_.set_piece(M63, WPawn);
    this->gameEngineStore_->board_.set_piece(M53, WPawn);
    this->gameEngineStore_->board_.set_piece(M43, WPawn);
    this->gameEngineStore_->board_.set_piece(M33, WPawn);
    this->gameEngineStore_->board_.set_piece(M23, WPawn);
    this->gameEngineStore_->board_.set_piece(M13, WPawn);
    this->gameEngineStore_->board_.set_piece(M97, BPawn);
    this->gameEngineStore_->board_.set_piece(M87, BPawn);
    this->gameEngineStore_->board_.set_piece(M77, BPawn);
    this->gameEngineStore_->board_.set_piece(M67, BPawn);
    this->gameEngineStore_->board_.set_piece(M57, BPawn);
    this->gameEngineStore_->board_.set_piece(M47, BPawn);
    this->gameEngineStore_->board_.set_piece(M37, BPawn);
    this->gameEngineStore_->board_.set_piece(M27, BPawn);
    this->gameEngineStore_->board_.set_piece(M17, BPawn);
    this->gameEngineStore_->board_.set_piece(M88, BBishop);
    this->gameEngineStore_->board_.set_piece(M28, BRook);
    this->gameEngineStore_->board_.set_piece(M99, BLance);
    this->gameEngineStore_->board_.set_piece(M89, BKnight);
    this->gameEngineStore_->board_.set_piece(M79, BSilver);
    this->gameEngineStore_->board_.set_piece(M69, BGold);
    this->gameEngineStore_->board_.set_piece(M59, BKing);
    this->gameEngineStore_->board_.set_piece(M49, BGold);
    this->gameEngineStore_->board_.set_piece(M39, BSilver);
    this->gameEngineStore_->board_.set_piece(M29, BKnight);
    this->gameEngineStore_->board_.set_piece(M19, BLance);

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
            // ----------------------------------------
            // 盤面
            // ----------------------------------------
            // 盤だけの描画（駒台を除く）
            else if (tokens[0] == "boardonly")
            {
                MuzBoardView::print(this->gameEngineStore_->get_board());
            }
            // 盤面だけセット
            //      - 例： `boardset lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL`
            //      - 例： `boardset 4k4/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/4K4`
            //      - 例： `boardset 9/9/9/9/9/9/9/9/9`
            else if (tokens[0] == "boardset")
            {
                this->gameEngineStore_->get_board().from_string(tokens[1]);
            }
            // ----------------------------------------
            // 駒台
            // ----------------------------------------
            // 先手駒台の描画
            else if (tokens[0] == "handb")
            {
                MuzHandStandView::print_black(this->gameEngineStore_->black_hand_stand_);
            }
            // 後手駒台の描画
            else if (tokens[0] == "handw")
            {
                MuzHandStandView::print_white(this->gameEngineStore_->white_hand_stand_);
            }
            // 駒台だけセット
            //      - 例： `handset 2PR`
            else if (tokens[0] == "handset")
            {
                MuzHandStandCollectionModel handStandCollectionSvc;
                auto result = handStandCollectionSvc.parse(tokens[1]);
                auto [b_hs, w_hs] = *result;

                this->gameEngineStore_->black_hand_stand_ = b_hs;
                this->gameEngineStore_->white_hand_stand_ = w_hs;
            }
            // ----------------------------------------
            // 手番
            // ----------------------------------------
            // 手番の描画
            else if (tokens[0] == "turnget")
            {
                // テスト
                std::cout << MuzTurnView::to_code(Color::Black) << "\n";
                std::cout << MuzTurnView::to_code(Color::White) << "\n";
            }
            // ----------------------------------------
            // 手数
            // ----------------------------------------
            // 手数の描画
            else if (tokens[0] == "plyget")
            {
                // テスト
                std::cout << "radix_half_ply = " << MuzPlyModel(123).get_radix_half_ply() << "\n";
            }
            // ----------------------------------------
            // 無いよ
            // ----------------------------------------
            else
            {
                std::cout << "そんなコマンド無い（＾～＾）\n";
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
    cout << "[n55a_game_engine] finalize." << endl;
}
