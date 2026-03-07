#pragma once
#include <map>
#include <string>
#include "muz_engine_option_abstract_model.hpp"
#include "muz_engine_option_textbox_model.hpp"
#include <ostream>      // std::ostream のため（普通は iostream で入ってる）
#include <vector>
#include <map>

/// <summary>
/// ２つの文字列の並び順の比較☆（＾～＾）
/// </summary>
struct MuzCaseInsensitiveLessModel {
	bool operator() (const std::string&, const std::string&) const;
};


/// <summary>
///		<pre>
/// エンジン・オプションのコレクション☆（＾～＾）
///		</pre>
/// </summary>
struct IMuzEngineSettingsModel
{


public:


	// ========================================
	// 演算子
	// ========================================


	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream&, const IMuzEngineSettingsModel&);


	// ========================================
	// メソッド
	// ========================================


	/// <summary>
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	virtual bool IsLegalOption(const std::string name) = 0;


	/// <summary>
	/// エンジン・オプションを登録するぜ☆（＾～＾）
	/// </summary>
	/// <param name="key"></param>
	/// <param name="option"></param>
	virtual void Put(const std::string key, MuzEngineOptionAbstractModel option) = 0;


	/// <summary>
	/// エンジン・オプション取得☆（＾～＾）
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	virtual const MuzEngineOptionAbstractModel& GetOptionByKey(const std::string key) const = 0;
	// XXX: 勉強中
	virtual MuzEngineOptionAbstractModel& GetOptionUniqueByKey(const std::string& key) const = 0;


	virtual std::vector<std::string> GetAllOptionKeys() const = 0;


	/// <summary>
	/// テキストボックス型のエンジン・オプション設定☆（＾～＾）
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	virtual void SetTextboxOption(const std::string key, std::string text) = 0;
};
