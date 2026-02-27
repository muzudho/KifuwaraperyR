#include "n11a55b105c_turn_view.hpp"


// ========================================
// 主要メソッド
// ========================================


std::string MuzTurnView::to_code(const Color color)
{
    switch (color)
    {
    case Black:
        return "b";
    case White:
        return "w";
    case Null:  // thru
    default:
        return " ";
    }
}
