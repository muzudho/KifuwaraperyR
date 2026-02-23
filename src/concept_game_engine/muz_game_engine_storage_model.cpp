#include "muz_game_engine_storage_model.hpp"


// ========================================
// 生成／破棄
// ========================================


MuzGameEngineStorageModel::MuzGameEngineStorageModel()
{
    // TODO: ［駒台］は［ポジション］クラスに移動したい（＾～＾）
    this->black_hand_stand_ = MuzHandStandModel{};
    this->white_hand_stand_ = MuzHandStandModel{};
}


// ========================================
// アクセッサー
// ========================================


/// <summary>
/// USIモードに入ったか。
/// </summary>
bool MuzGameEngineStorageModel::is_usi() const
{
    return this->is_usi_;
}
void MuzGameEngineStorageModel::set_usi()
{
    this->is_usi_ = true;
}


const MuzBoardModel& MuzGameEngineStorageModel::get_board() const
{
    return this->board_;
}