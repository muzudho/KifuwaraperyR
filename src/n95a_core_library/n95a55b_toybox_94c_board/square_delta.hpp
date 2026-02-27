//
// 📄 マスの位置の差分
//

#pragma once

/// <summary>
///		<pre>
/// マスの位置の差分
/// 
///		- いわゆる縦型ビットボード。M11 が 0、M12 が 1、M99 が 80（＾～＾）
///		</pre>
/// </summary>
enum SquareDelta
{
	/// <summary>
	/// 同一の Square にあるとき
	/// </summary>
	DeltaNothing = 0,

	/// <summary>
	/// 北
	/// </summary>
	DeltaN = -1,
	
	/// <summary>
	/// 東
	/// </summary>
	DeltaE = -9,
	
	/// <summary>
	/// 南
	/// </summary>
	DeltaS = 1,
	
	/// <summary>
	/// 西
	/// </summary>
	DeltaW = 9,

	DeltaNE = DeltaN + DeltaE,
	DeltaSE = DeltaS + DeltaE,
	DeltaSW = DeltaS + DeltaW,
	DeltaNW = DeltaN + DeltaW
};
