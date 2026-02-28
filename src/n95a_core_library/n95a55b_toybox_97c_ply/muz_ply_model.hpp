#pragma once

#include "ply.hpp"
#include <string_view>

/// <summary>
/// 手数
/// </summary>
class MuzPlyModel
{


    // ========================================
    // 生成／破棄
    // ========================================


public:
    MuzPlyModel(Ply ply = (Ply)0);


    // ========================================
    // フィールド
    // ========================================


private:
    /// <summary>
    ///     <pre>
    /// 何手目か。
    /// 
    ///     - 時間管理の役に立つ。
    ///     </pre>
    /// </summary>
    Ply ply_;


    // ========================================
    // アクセッサー
    // ========================================


public:
    /// <summary>
    /// 何手目かを取得
    /// </summary>
    /// <returns></returns>
    Ply get_ply() const { return this->ply_; }


    /// <summary>
    /// 何手目かをセット
    /// </summary>
    /// <param name="turn"></param>
    void set_ply(const Ply ply) { this->ply_ = ply; }


    // ========================================
    // 主要メソッド
    // ========================================


    /// <summary>
    ///     <pre>
    /// 文字列から何手目かをセット。
    /// 
    ///     - エラーの時は何もセットせず偽を返す。
    ///     </pre>
    /// </summary>
    bool from_string(std::string_view turn_str);
};
