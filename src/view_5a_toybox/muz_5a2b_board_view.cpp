#include "muz_5a2b_board_view.hpp"
#include <iomanip>   // ← これ必須！ setw, right とか入ってる


// ========================================
// 主要メソッド
// ========================================


void MuzBoardView::print(const MuzBoardModel& b)
{
    std::cout << "+--\n"
        << "+" << std::right << std::setw(2) << b.get_piece(Square::I9) << "\n";
}
