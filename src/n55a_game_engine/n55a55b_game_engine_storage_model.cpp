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
    return this->m_engineSettings;
}
MuzEngineSettingsModel& MuzGameEngineStorageModel::get_engine_settings()
{
    return this->m_engineSettings;
}


const MuzStationalyPositionModel& MuzGameEngineStorageModel::get_position() const
{
    return this->position_;
}
MuzStationalyPositionModel& MuzGameEngineStorageModel::get_position()
{
    return this->position_;
}
