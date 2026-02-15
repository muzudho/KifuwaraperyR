//
// 列挙型に演算子を追加（＾▽＾）
//
#pragma once


//// +=, -=, *=, /=, +, -, *, /, 単項 -, 前置 ++, 前置 --, 後置 ++, 後置 -- を定義しています。
//
//// C++11 の書き方（＾～＾） C++20 なら template で書いた方がよい（＾～＾）
//// enum 型に演算子を定義しています。
//// 
////		- `T` は enum 型を渡してください。
////		- `#define` は複数行に渡って書くものではないから、末尾に `\` を付けて、次の行に続いているとみなしている。
//#define OverloadEnumOperators(T)										\
//	inline void operator += (T& lhs, const int rhs) { lhs  = static_cast<T>(static_cast<int>(lhs) + rhs); } \
//	inline void operator += (T& lhs, const T   rhs) { lhs += static_cast<int>(rhs); } \
//	inline void operator -= (T& lhs, const int rhs) { lhs  = static_cast<T>(static_cast<int>(lhs) - rhs); } \
//	inline void operator -= (T& lhs, const T   rhs) { lhs -= static_cast<int>(rhs); } \
//	inline void operator *= (T& lhs, const int rhs) { lhs  = static_cast<T>(static_cast<int>(lhs) * rhs); } \
//	inline void operator /= (T& lhs, const int rhs) { lhs  = static_cast<T>(static_cast<int>(lhs) / rhs); } \
//	inline constexpr T operator + (const T   lhs, const int rhs) { return static_cast<T>(static_cast<int>(lhs) + rhs); } \
//	inline constexpr T operator + (const T   lhs, const T   rhs) { return lhs + static_cast<int>(rhs); } \
//	inline constexpr T operator - (const T   lhs, const int rhs) { return static_cast<T>(static_cast<int>(lhs) - rhs); } \
//	inline constexpr T operator - (const T   lhs, const T   rhs) { return lhs - static_cast<int>(rhs); } \
//	inline constexpr T operator * (const T   lhs, const int rhs) { return static_cast<T>(static_cast<int>(lhs) * rhs); } \
//	inline constexpr T operator * (const int lhs, const T   rhs) { return rhs * lhs; } \
//	inline constexpr T operator * (const T   lhs, const T   rhs) { return lhs * static_cast<int>(rhs); } \
//	inline constexpr T operator / (const T   lhs, const int rhs) { return static_cast<T>(static_cast<int>(lhs) / rhs); } \
//	inline constexpr T operator - (const T   rhs) { return static_cast<T>(-static_cast<int>(rhs)); } \
//	inline constexpr T operator ++ (T& lhs) { lhs += 1; return lhs; } /* 前置 */	\
//	inline constexpr T operator -- (T& lhs) { lhs -= 1; return lhs; } /* 前置 */	\
//	inline constexpr T operator ++ (T& lhs, int) { const T temp = lhs; lhs += 1; return temp; } /* 後置 */ \
//	inline constexpr T operator -- (T& lhs, int) { const T temp = lhs; lhs -= 1; return temp; } /* 後置 */


// +=, -=, *=, /=, +, -, *, /, 単項 -, 前置 ++, 前置 --, 後置 ++, 後置 -- を定義しています。


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
