#include "muz_transpositional_position_model.hpp"


// ========================================
// アクセッサー
// ========================================


const MuzStationalyPositionModel& MuzTranspositionalPositionModel::get_stationaly_position() const
{
    return this->stationaly_position_;
}
MuzStationalyPositionModel& MuzTranspositionalPositionModel::get_stationaly_position()
{
    return this->stationaly_position_;
}
