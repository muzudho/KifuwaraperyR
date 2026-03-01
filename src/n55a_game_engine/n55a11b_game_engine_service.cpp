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
#include <span>     // std::span を使うために必要

using namespace std;



// ========================================
// 生成／破棄
// ========================================


/// <summary>
/// 生成
/// </summary>
MuzGameEngineService::MuzGameEngineService()
{
    this->game_engine_store_ = std::unique_ptr<MuzGameEngineStorageModel>(new MuzGameEngineStorageModel);
}


/// <summary>
/// 破棄。
/// </summary>
MuzGameEngineService::~MuzGameEngineService()
{
    this->game_engine_store_.reset();
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
        &this->game_engine_store_->m_engineSettings,
        // onHashSizeChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->game_engine_store_.get()->m_tt.setSize(opt);
        },
        // onHashCleared:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->game_engine_store_.get()->m_tt.Clear();
        },
        // onEvalDirChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: std::unique_ptr<KkKkpKppStorage1>(new KkKkpKppStorage1)->initialize_10a600b(opt, true);
        },
        // onMaxThreadsPerSplitPointChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->game_engine_store_.get()->m_pub.ReadUSIOptions(this->game_engine_store_.get());
        },
        // onThreadsChanged:
        [](auto opt)    // [this](auto opt)
        {
            // TODO: this->game_engine_store_.get()->m_pub.ReadUSIOptions(this->game_engine_store_.get());
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
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HRook, 0);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HBishop, 1);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HGold, 0);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HSilver, 4);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HKnight, 3);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HLance, 1);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>().set_count(HPawn, 2);   // とりあえず歩を２枚持ってることにするぜ（＾ｑ＾）

    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HRook, 2);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HBishop, 0);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HGold, 1);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HSilver, 0);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HKnight, 1);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HLance, 0);
    this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>().set_count(HPawn, 3);   // とりあえず歩を３枚持ってることにするぜ（＾ｑ＾）

    // テスト：盤の初期化
    // TODO: これらの変数は、ポジションに移動したい（＾～＾）
    this->game_engine_store_->get_position().get_board().set_piece(M91, WLance);
    this->game_engine_store_->get_position().get_board().set_piece(M81, WKnight);
    this->game_engine_store_->get_position().get_board().set_piece(M71, WSilver);
    this->game_engine_store_->get_position().get_board().set_piece(M61, WGold);
    this->game_engine_store_->get_position().get_board().set_piece(M51, WKing);
    this->game_engine_store_->get_position().get_board().set_piece(M41, WGold);
    this->game_engine_store_->get_position().get_board().set_piece(M31, WSilver);
    this->game_engine_store_->get_position().get_board().set_piece(M21, WKnight);
    this->game_engine_store_->get_position().get_board().set_piece(M11, WLance);
    this->game_engine_store_->get_position().get_board().set_piece(M82, WRook);
    this->game_engine_store_->get_position().get_board().set_piece(M22, WBishop);
    this->game_engine_store_->get_position().get_board().set_piece(M93, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M83, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M73, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M63, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M53, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M43, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M33, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M23, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M13, WPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M97, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M87, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M77, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M67, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M57, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M47, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M37, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M27, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M17, BPawn);
    this->game_engine_store_->get_position().get_board().set_piece(M88, BBishop);
    this->game_engine_store_->get_position().get_board().set_piece(M28, BRook);
    this->game_engine_store_->get_position().get_board().set_piece(M99, BLance);
    this->game_engine_store_->get_position().get_board().set_piece(M89, BKnight);
    this->game_engine_store_->get_position().get_board().set_piece(M79, BSilver);
    this->game_engine_store_->get_position().get_board().set_piece(M69, BGold);
    this->game_engine_store_->get_position().get_board().set_piece(M59, BKing);
    this->game_engine_store_->get_position().get_board().set_piece(M49, BGold);
    this->game_engine_store_->get_position().get_board().set_piece(M39, BSilver);
    this->game_engine_store_->get_position().get_board().set_piece(M29, BKnight);
    this->game_engine_store_->get_position().get_board().set_piece(M19, BLance);

    MuzCliService cliSvc;

    // TODO: ここで実際のコマンド処理を書く
    cliSvc.set_process_command_line([this](const std::string& line)
        {
            if (!this->game_engine_store_->is_usi()) {
                std::cout << "処理するよ: " << line << "\n";
            }

            MuzStringService stringSvc;

            // 半角スペース ' ' で分割
            auto tokens = stringSvc.split(line, ' ');


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
                this->game_engine_store_->set_usi();

                // USIプロトコルのバージョンを返す。
                std::cout << "id name " << my_name_ << "\nid author (Derivation)Takahashi Satoshi (Base)Hiraoka Takuya\nusiok" << "\n";

                // TODO: セット・オプション付けてください： std::cout << "id name " << my_name_ << "\nid author (Derivation)Takahashi Satoshi (Base)Hiraoka Takuya\n" << game_engine_store_.m_engineSettings << "\nusiok" << "\n";
            }
            else if (line == "isready")
            {
                // エンジンが準備できたら、"readyok" を返す。
                std::cout << "readyok" << "\n";
            }
            else if (line == "setoption")
            {
                // TODO: エンジンのオプションを設定するコマンド。これが来たら、オプションを変更する。
                //game_engine_store_.SetOption(ssCmd);
            }
            else if (line == "usinewgame")
            {
                //                // 新しいゲームの開始を知らせるコマンド。これが来たら、前のゲームの情報をクリアする。
                //                game_engine_store_.m_tt.Clear();
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
            // ----------------------------------------
            // 局面
            // ----------------------------------------
            //      - 例： `position sfen lnsgkgsnl/9/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL w - 1 moves 5a6b 7g7f 3a3b`
            else if (tokens[0] == "position")
            {

                // TODO: 局面を設定するコマンド。これが来たら、局面を変更する。
                //usiOperation.SetPosition(pos, ssCmd);
                // TODO: tokens[1] ではなくて、 `position` 以降の全ての文字列を渡したい。
                //this->game_engine_store_->get_position().Set(tokens[1]);

                std::span parameter_tokens{ tokens.begin() + 1, tokens.end() };
                this->game_engine_store_->get_position().Set(parameter_tokens);
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
            else if (tokens[0] == "boardget")
            {
                MuzBoardView::print(this->game_engine_store_->get_position().get_board());
            }
            // 盤面だけセット
            //      - 例： `boardset lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL`
            //      - 例： `boardset 4k4/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/4K4`
            //      - 例： `boardset 9/9/9/9/9/9/9/9/9`
            else if (tokens[0] == "boardset")
            {
                this->game_engine_store_->get_position().get_board().update_from_string(tokens[1]);
            }
            // ----------------------------------------
            // 駒台
            // ----------------------------------------
            // 両駒台の描画
            else if (tokens[0] == "handget")
            {
                MuzHandStandView::print_black(this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>());
                MuzHandStandView::print_white(this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>());
            }
            // 先手駒台の描画
            else if (tokens[0] == "handb")
            {
                MuzHandStandView::print_black(this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<Black>());
            }
            // 後手駒台の描画
            else if (tokens[0] == "handw")
            {
                MuzHandStandView::print_white(this->game_engine_store_->get_position().get_hand_stand_collection().get_hand_stand<White>());
            }
            // 駒台だけセット
            //      - 例： `handset 2PR`
            else if (tokens[0] == "handset")
            {
                this->game_engine_store_->get_position().get_hand_stand_collection().update_from_string(tokens[1]);
            }
            // ----------------------------------------
            // 手番
            // ----------------------------------------
            // 手番の描画
            else if (tokens[0] == "turnget")
            {
                std::cout << "turn_color = " << MuzTurnView::to_code(this->game_engine_store_->get_position().get_turn().get_color()) << "\n";
            }
            // 手番の設定
            else if (tokens[0] == "turnset")
            {
                this->game_engine_store_->get_position().get_turn().update_from_string(tokens[1]);
            }
            // ----------------------------------------
            // 手数
            // ----------------------------------------
            // 手数の描画
            else if (tokens[0] == "radixhalfplyget")
            {
                // テスト
                std::cout << "radix_half_ply = " << this->game_engine_store_->get_position().get_ply_obj().get_radix_half_ply() << "\n";
            }
            // 手数の設定
            else if (tokens[0] == "halfplyset")
            {
                this->game_engine_store_->get_position().get_ply_obj().update_from_string(
                    this->game_engine_store_->get_position().get_turn(),
                    tokens[1]);
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
