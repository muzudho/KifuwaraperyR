#pragma once

#include "../../core_library/lib_55a_toybox_95b_hand_stand/color.hpp"
#include "../../core_library/lib_55a_toybox_95b_hand_stand/muz_hand_stand_model.hpp"
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
