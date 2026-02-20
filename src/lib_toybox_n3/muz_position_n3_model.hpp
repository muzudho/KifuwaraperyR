#pragma once

// MuzPositionN3Model では使ってないヘッダーファイルでも、他のクラスが MuzPositionN3Model をインクルードすれば lib_toybox_n3 のヘッダーファイルが全部付いてくるようにします。
#include "../lib_toybox_n2/muz_position_n2_model.hpp"
#include "square_ope.hpp"
#include <string_view>

class MuzPositionN3Model : public MuzPositionN2Model
{

protected:
	// ========================================
	// 主要メソッド
	// ========================================

	bool ParseBoard(std::string_view board_str);

};
