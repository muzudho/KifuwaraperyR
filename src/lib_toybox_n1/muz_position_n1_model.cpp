//
// 📄 局面の状態を表すクラス
//
#include "muz_position_n1_model.hpp"


// ========================================
// アクセッサ
// ========================================


/// <summary>
/// 何手目か
/// </summary>
/// <returns></returns>
Ply MuzPositionN1Model::GetGamePly()
{
	return this->m_gamePly_;
}
