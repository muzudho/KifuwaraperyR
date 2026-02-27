//
// 列挙型に演算子を追加（＾▽＾）
//
#pragma once
#include <type_traits>	// std::underlying_type_t を使うために必要


// +=, -=, *=, /=, +, -, *, /, 単項 -, 前置 ++, 前置 --, 後置 ++, 後置 -- を定義しています。


//* TODO
// ヘルパー（C++23なら std::to_underlying が標準で使える）
template <typename Enum>
constexpr auto to_underlying(Enum e) noexcept
-> std::underlying_type_t<Enum>
{
	return static_cast<std::underlying_type_t<Enum>>(e);
}


// TODO
template <typename Enum>
concept EnumWithUnderlyingIntegral =
std::is_enum_v<Enum> &&
std::is_integral_v<std::underlying_type_t<Enum>>;


/// <summary>
/// a + b
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator+(E a, E b) noexcept {
	return static_cast<E>(to_underlying(a) + to_underlying(b));
}


/// <summary>
/// a - b
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator-(E a, E b) noexcept {
	return static_cast<E>(to_underlying(a) - to_underlying(b));
}


/// <summary>
/// a * b
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator*(E a, E b) noexcept {
	return static_cast<E>(to_underlying(a) * to_underlying(b));
}


/// <summary>
/// a / b
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator/(E a, E b) noexcept {
	return static_cast<E>(to_underlying(a) / to_underlying(b));
}


/// <summary>
/// - a
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator-(E a) noexcept {
	return static_cast<E>(-to_underlying(a));
}


/// <summary>
/// ++e
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E& operator++(E& e) noexcept {
	e = static_cast<E>(to_underlying(e) + 1);
	return e;
}


/// <summary>
/// --e
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E& operator--(E& e) noexcept {
	e = static_cast<E>(to_underlying(e) - 1);
	return e;
}


/// <summary>
/// e++
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator++(E& e, int) noexcept {
	E old = e;
	++e;
	return old;
}


/// <summary>
/// e--
/// </summary>
template <EnumWithUnderlyingIntegral E>
constexpr E operator--(E& e, int) noexcept {
	E old = e;
	--e;
	return old;
}
// */
