//
// 📄 マス
//

#pragma once

#include "color.hpp"
#include "square.hpp"
#include "square_delta.hpp"
#include "file.hpp"
#include "rank.hpp"

/// <summary>
///		<pre>
/// マス番号。
/// 
///		盤面を [0, 80] の整数の index で表す
///		I9 = 1一, I1 = 1九, A1 = 9九（チェス盤の座標）
///
///		A9, B9, C9, D9, E9, F9, G9, H9, I9,
///		A8, B8, C8, D8, E8, F8, G8, H8, I8,
///		A7, B7, C7, D7, E7, F7, G7, H7, I7,
///		A6, B6, C6, D6, E6, F6, G6, H6, I6,
///		A5, B5, C5, D5, E5, F5, G5, H5, I5,
///		A4, B4, C4, D4, E4, F4, G4, H4, I4,
///		A3, B3, C3, D3, E3, F3, G3, H3, I3,
///		A2, B2, C2, D2, E2, F2, G2, H2, I2,
///		A1, B1, C1, D1, E1, F1, G1, H1, I1,
///
///		Bitboard のビットが縦に並んでいて、
///		0 ビット目から順に、以下の位置と対応させる。
///		</pre>
/// </summary>
enum Square
{
	I9, I8, I7, I6, I5, I4, I3, I2, I1,
	H9, H8, H7, H6, H5, H4, H3, H2, H1,
	G9, G8, G7, G6, G5, G4, G3, G2, G1,
	F9, F8, F7, F6, F5, F4, F3, F2, F1,
	E9, E8, E7, E6, E5, E4, E3, E2, E1,
	D9, D8, D7, D6, D5, D4, D3, D2, D1,
	C9, C8, C7, C6, C5, C4, C3, C2, C1,
	B9, B8, B7, B6, B5, B4, B3, B2, B1,
	A9, A8, A7, A6, A5, A4, A3, A2, A1,
	SquareNum, // = 81

    SquareNoLeftNum = D9,	// 盤を２バイトで表現しているから（＾～＾）？ 盤面の左側のマスの数。これも 40 である必要はない。

	B_hand_pawn = SquareNum + -1,
	B_hand_lance = B_hand_pawn + 18,
	B_hand_knight = B_hand_lance + 4,
	B_hand_silver = B_hand_knight + 4,
	B_hand_gold = B_hand_silver + 4,
	B_hand_bishop = B_hand_gold + 4,
	B_hand_rook = B_hand_bishop + 2,
	W_hand_pawn = B_hand_rook + 2,
	W_hand_lance = W_hand_pawn + 18,
	W_hand_knight = W_hand_lance + 4,
	W_hand_silver = W_hand_knight + 4,
	W_hand_gold = W_hand_silver + 4,
	W_hand_bishop = W_hand_gold + 4,
	W_hand_rook = W_hand_bishop + 2,
	SquareHandNum = W_hand_rook + 3
};


/// <summary>
/// マス番号の操作
/// </summary>
class ConvSquare {


public:


    /// <summary>
    /// 先手のときは BRANK, 後手のときは WRANK より target が前の段にあるなら true を返す。
    /// </summary>
    /// <param name="us"></param>
    /// <param name="bRank"></param>
    /// <param name="wRank"></param>
    /// <param name="target"></param>
    /// <returns></returns>
    static inline bool IS_IN_FRONT_OF10(Color us, Rank bRank, Rank wRank, const Rank target) {
        return (us == Color::Black ? (target < bRank) : (wRank < target));
    }


    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="US"></typeparam>
    /// <param name="bRank"></param>
    /// <param name="wRank"></param>
    /// <param name="target"></param>
    /// <returns></returns>
    template<Color US>
    static inline bool IS_BEHIND10(Rank bRank, Rank wRank, const Rank target)
    {
        return (US == Black ? (bRank < target) : (target < wRank));
    }


    /// <summary>
    /// 未使用☆？
    /// </summary>
    /// <typeparam name="US"></typeparam>
    /// <param name="bFile"></param>
    /// <param name="wFile"></param>
    /// <param name="target"></param>
    /// <returns></returns>
    template<Color US>
    static inline bool IS_LEFT_OF10(File bFile, File wFile, const File target) {
        return (US == Black ? (bFile < target) : (target < wFile));
    }


    /// <summary>
    /// 未使用☆？
    /// </summary>
    /// <typeparam name="US"></typeparam>
    /// <param name="bFile"></param>
    /// <param name="wFile"></param>
    /// <param name="target"></param>
    /// <returns></returns>
    template<Color US>
    static inline bool IS_RIGHT_OF10(File bFile, File wFile, const File target) {
        return (US == Black ? (target < bFile) : (wFile < target));
    }


    /// <summary>
    /// s が Square の中に含まれているか判定
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    static inline bool CONTAINS_OF10(const Square s) {
        return (0 <= s) && (s < SquareNum);
    }


    /// <summary>
    /// File, Rank のどちらかがおかしいかも知れない時は、
    /// こちらを使う。
    /// こちらの方が遅いが、どんな File, Rank にも対応している。
    /// </summary>
    /// <param name="f"></param>
    /// <param name="r"></param>
    /// <returns></returns>
    static inline bool CONTAINS_OF20(const File f, const Rank r) {
        return ConvFile::CONTAINS_OF10(f) && ConvRank::CONTAINS_OF10(r);
    }


    /// <summary>
    /// 速度が必要な場面で使用するなら、テーブル引きの方が有効だと思う。
    /// </summary>
    /// <param name="f"></param>
    /// <param name="r"></param>
    /// <returns></returns>
    static inline constexpr Square FROM_FILE_RANK10(const File f, const Rank r) {
        return static_cast<Square>(static_cast<int>(f) * 9 + static_cast<int>(r));
    }


    /// <summary>
    /// 速度が必要な場面で使用する。
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    static inline Rank TO_RANK10(const Square s) {
        assert(ConvSquare::CONTAINS_OF10(s));
        // 計算せず、テーブル引き☆（＾ｑ＾）
        return g_squareToRank[s];
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    static inline File TO_FILE10(const Square s) {
        assert(ConvSquare::CONTAINS_OF10(s));
        return g_squareToFile[s];
    }


    /// <summary>
    /// 末尾の改行付きで☆
    /// </summary>
    /// <param name="sq"></param>
    /// <returns></returns>
    static inline std::string TO_2CHARS_N0_STRING_USI40(const Square sq) {
        const Rank r = ConvSquare::TO_RANK10(sq);
        const File f = ConvSquare::TO_FILE10(sq);
        const char ch[] = { ConvFile::TO_CHAR_USI10(f), ConvRank::TO_CHAR_USI10(r), '\0' };
        return std::string(ch);
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="sq"></param>
    /// <returns></returns>
    static inline std::string TO_STRING_CSA40(const Square sq) {
        const Rank r = ConvSquare::TO_RANK10(sq);
        const File f = ConvSquare::TO_FILE10(sq);
        const char ch[] = { ConvFile::TO_CHAR_CSA10(f), ConvRank::TO_CHAR_CSA10(r), '\0' };
        return std::string(ch);
    }


    /// <summary>
    /// 後手の位置を先手の位置へ変換
    /// </summary>
    /// <param name="sq"></param>
    /// <returns></returns>
    static inline constexpr Square INVERSE10(const Square sq) {
        return (Square)(SquareNum - 1 - sq);
    }


    /// <summary>
    /// Square の左右だけ変換
    /// </summary>
    /// <param name="sq"></param>
    /// <returns></returns>
    static inline Square INVERSE_FILE40(const Square sq) {
        return ConvSquare::FROM_FILE_RANK10(
            ConvFile::INVERSE10(
                ConvSquare::TO_FILE10(sq)
            ),
            ConvSquare::TO_RANK10(sq)
        );
    }


    /// <summary>
    /// ビショップ・イン・デンジャーで使用☆
    /// </summary>
    /// <param name="c"></param>
    /// <param name="sq"></param>
    /// <returns></returns>
    static inline constexpr Square INVERSE_IF_WHITE20(const Color c, const Square sq) {
        return (c == Black ? sq : INVERSE10(sq));
    }


    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="US"></typeparam>
    /// <param name="fromOrToRank"></param>
    /// <returns></returns>
    template<Color US>
    static inline bool CAN_PROMOTE10(const Rank fromOrToRank) {
#if 1
        static_assert(Black == 0, "");
        static_assert(Rank9 == 0, "");
        return static_cast<bool>(0x1c00007u & (1u << ((US << 4) + fromOrToRank)));
#else
        // 同じ意味。
        return (US == Black ? IsInFrontOf<Black, Rank6, Rank4>(fromOrToRank) : IsInFrontOf<White, Rank6, Rank4>(fromOrToRank));
#endif
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="c"></param>
    /// <param name="fromOrToRank"></param>
    /// <returns></returns>
    static inline bool CAN_PROMOTE10b(const Color c, const Rank fromOrToRank) {
#if 1
        static_assert(Black == 0, "");
        static_assert(Rank9 == 0, "");
        return static_cast<bool>(0x1c00007u & (1u << ((c << 4) + fromOrToRank)));
#else
        // 同じ意味。
        return (c == Black ? IsInFrontOf<Black, Rank6, Rank4>(fromOrToRank) : IsInFrontOf<White, Rank6, Rank4>(fromOrToRank));
#endif
    }
};

template<typename E>
constexpr auto underlying(E e) noexcept -> std::underlying_type_t<E> {
    return static_cast<std::underlying_type_t<E>>(e);
}

// sq + delta
constexpr Square operator+(Square sq, SquareDelta delta) noexcept {
    return static_cast<Square>(underlying(sq) + underlying(delta));
}

// sq += delta
constexpr Square& operator+=(Square& sq, SquareDelta delta) noexcept {
    sq = static_cast<Square>(underlying(sq) + underlying(delta));
    return sq;
}

// sq - delta
constexpr Square operator-(Square sq, SquareDelta delta) noexcept {
    return static_cast<Square>(underlying(sq) - underlying(delta));
}

// sq -= delta
constexpr Square& operator-=(Square& sq, SquareDelta delta) noexcept {
    sq = static_cast<Square>(underlying(sq) - underlying(delta));
    return sq;
}