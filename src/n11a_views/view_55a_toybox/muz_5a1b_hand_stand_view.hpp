#pragma once

#include "../../n95a_core_library/n95a55b_toybox_95c_hand_stand/color.hpp"
#include "../../n95a_core_library/n95a55b_toybox_95c_hand_stand/muz_hand_stand_model.hpp"
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
