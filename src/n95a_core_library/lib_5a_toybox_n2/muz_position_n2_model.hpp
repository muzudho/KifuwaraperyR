#pragma once

// MuzPositionN2Model では使ってないヘッダーファイルでも、他のクラスが MuzPositionN2Model をインクルードすれば lib_5a_toybox_n2 のヘッダーファイルが全部付いてくるようにします。
#include "../lib_5a_toybox_n1/muz_position_n1_model.hpp"
#include <string_view>

class MuzPositionN2Model : public MuzPositionN1Model
{


    // ========================================
    // フィールド
    // ========================================


protected:


    // ========================================
    // アクセッサ
    // ========================================


public:


    // ========================================
    // 主要メソッド
    // ========================================


    /// <summary>
    ///     <pre>
    /// 局面をセット
    /// 
    ///     - 旧名： `Position::set()`
    ///     </pre>
    /// </summary>
    /// <param name="sfen"></param>
    void Set(std::string_view sfen);
};
