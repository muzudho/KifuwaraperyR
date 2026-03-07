#include "muz_rucksack_model.hpp"


// ========================================
// アクセッサー
// ========================================


const MuzTranspositionalPositionModel& MuzRucksackModel::get_transpositonal_position() const
{
    return this->transpositional_position_;
}
MuzTranspositionalPositionModel& MuzRucksackModel::get_transpositonal_position()
{
    return this->transpositional_position_;
}
