//
// 筋
// 
//		- 列とも。
//

#pragma once

#include "square.hpp"

/// <summary>
/// 筋の定数
/// </summary>
enum File {
	/// <summary>
	/// ９筋目か☆（＾～＾）？
	/// </summary>
	FileI,
	
	FileH, FileG, FileF, FileE, FileD, FileC, FileB,
	
	/// <summary>
	/// １筋目か☆（＾～＾）？
	/// </summary>
	FileA,
	
	/// <summary>
	/// 列挙型の終端
	/// </summary>
	FileNum,

	FileNoLeftNum = FileD
};

/// <summary>
/// 
/// </summary>
extern const File g_squareToFile[SquareNum];


/// <summary>
/// 筋の操作
/// </summary>
class ConvFile {


public:


	/// <summary>
	/// 左右変換
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	static inline constexpr File INVERSE10(const File f) { return (File)(FileNum - 1 - f); }


	/// <summary>
	/// 
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	static inline bool CONTAINS_OF10(const File f) { return (0 <= f) && (f < FileNum); }


	/// <summary>
	/// 
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	static inline char TO_CHAR_USI10(const File f) { return '1' + f; }


	/// <summary>
	/// 
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	static inline char TO_CHAR_CSA10(const File f) { return '1' + f; }


	/// <summary>
	/// 
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	static inline File FROM_CHAR_CSA10(const char c) { return static_cast<File>(c - '1'); }


	/// <summary>
	/// 
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	static inline File FROM_CHAR_USI10(const char c) { return static_cast<File>(c - '1'); }
};
