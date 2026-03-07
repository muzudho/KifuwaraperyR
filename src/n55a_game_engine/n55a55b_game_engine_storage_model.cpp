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


const MuzEngineSettingsModel& MuzGameEngineStorageModel::get_engine_settings() const
{
    return this->engine_settings_;
}
MuzEngineSettingsModel& MuzGameEngineStorageModel::get_engine_settings()
{
    return this->engine_settings_;
}


const MuzStationalyPositionModel& MuzGameEngineStorageModel::get_position() const
{
    return this->position_;
}
MuzStationalyPositionModel& MuzGameEngineStorageModel::get_position()
{
    return this->position_;
}
