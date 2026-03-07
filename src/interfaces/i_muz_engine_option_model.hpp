#pragma once
#include <functional>
#include <string>
#include <format>  // C++20

/// <summary>
/// エンジン・オプション的☆（＾ｑ＾）
/// </summary>
class IMuzEngineOptionModel
{


public:


	// ========================================
	// 演算子
	// ========================================


	/// <summary>
    /// 代入演算子☆
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	virtual IMuzEngineOptionModel& operator = (const std::string& v) = 0;


	/// <summary>
    /// 整数化☆
	/// </summary>
	virtual operator int() const = 0;


	/// <summary>
    /// 文字列化☆
	/// </summary>
	virtual operator std::string() const = 0;


	// ========================================
	// その他のメソッド
	// ========================================


	/// <summary>
	/// 既定値
	/// </summary>
	/// <returns></returns>
	virtual std::string	GetDefaultValue() const = 0;


	/// <summary>
	/// 型
	/// </summary>
	/// <returns></returns>
	virtual std::string	GetType() const = 0;


	/// <summary>
	/// 最小値
	/// </summary>
	/// <returns></returns>
	virtual int GetMin() const = 0;


	/// <summary>
	/// 最大値
	/// </summary>
	/// <returns></returns>
	virtual int GetMax() const = 0;


	/// <summary>
    /// USIコード化☆（＾～＾）
	/// </summary>
	/// <returns></returns>
	virtual std::string ToUSICode()	const = 0;
};
