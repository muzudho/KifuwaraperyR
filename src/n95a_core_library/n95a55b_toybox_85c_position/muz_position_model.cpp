#include "muz_position_model.hpp"


// ========================================
// 生成／破棄
// ========================================


MuzPositionModel::MuzPositionModel()
{
    //// 盤上を空っぽにするぜ（＾～＾）
    //this->board_ = MuzBoardModel{};
}


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
