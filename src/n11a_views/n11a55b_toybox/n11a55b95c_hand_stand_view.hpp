#pragma once

#include "../../n95a_core_library/n95a87b_stationaly_position/n95a87b71c_hand_stand/muz_hand_stand_model.hpp"
#include <iostream>

/// <summary>
/// 駒台の描画
/// </summary>
class MuzHandStandView
{
public:


    // ========================================
    // 主要メソッド
    // ========================================


    static void print_black(const MuzHandStandModel& handStand);
    static void print_white(const MuzHandStandModel& handStand);
};
