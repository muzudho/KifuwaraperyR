#pragma once
#include <spdlog/spdlog.h>
#include <string>	// std::string を使うために必要
#include <iostream>    // std::cerr を使うために必要


class MuzDefaultLoggerModel
{
public:


	// ========================================
	// 生成／破棄
	// ========================================


	// ========================================
	// その他のメソッド
	// ========================================


	void trace(const std::string& message) const;
	void debug(const std::string& message) const;
	void info(const std::string& message) const;
	void warn(const std::string& message) const;
	void error(const std::string& message) const;
	void fatal(const std::string& message) const;

private:

};
