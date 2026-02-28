#include "muz_position_model.hpp"


// ========================================
// アクセッサー
// ========================================


const MuzBoardModel& MuzPositionModel::get_board() const
{
    return this->board_;
}
MuzBoardModel& MuzPositionModel::get_board()
{
    return this->board_;
}
