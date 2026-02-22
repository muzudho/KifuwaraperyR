#include "muz_game_engine_storage_model.hpp"


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
