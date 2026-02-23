#include "muz_5a24b1c_piece_view.hpp"
#include "muz_5a25b_board_view.hpp"
#include <iomanip>   // ← これ必須！ setw, right とか入ってる


// ========================================
// 主要メソッド
// ========================================


void MuzBoardView::print(const MuzBoardModel& b)
{
    auto pretty_piece = [&](const Square sq) -> std::string
    {
        return MuzPieceView::pretty(b.get_piece(sq));
    };

    std::cout << "+--\n"
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M91)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M81)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M71)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M61)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M51)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M41)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M31)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M21)
        << "|" << std::right << std::setw(2) << pretty_piece(Square::M11)
        << "\n";
}
