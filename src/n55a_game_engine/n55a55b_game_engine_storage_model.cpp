#include "n55a55b_game_engine_storage_model.hpp"


// ========================================
// 生成／破棄
// ========================================


MuzGameEngineStorageModel::MuzGameEngineStorageModel()
{
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


const MuzPositionModel& MuzGameEngineStorageModel::get_position() const
{
    return this->position_;
}
MuzPositionModel& MuzGameEngineStorageModel::get_position()
{
    return this->position_;
}
