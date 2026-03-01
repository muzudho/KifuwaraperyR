#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class MuzStringService
{
public:


    std::vector<std::string> split(const std::string& line, char delimiter = ' ')
    {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> tokens;

        // デリミター（区切り文字）で分割。
        while (std::getline(ss, item, delimiter)) {
            if (!item.empty()) { // 空文字を除外したい場合
                tokens.push_back(item);
            }
        }

        return tokens;
    }
};
