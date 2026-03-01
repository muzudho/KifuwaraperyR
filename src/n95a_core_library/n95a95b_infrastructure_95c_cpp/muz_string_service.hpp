#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ranges>	// std::views::split と std::views::transform を使うために必要
#include <string_view>
#include <vector>

class MuzStringService
{
public:


    // XXX: これでも動くが、std::string_view のコレクションを返したい（＾～＾）
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


    ///// <summary>
    /////     <pre>
    ///// デリミター（区切り文字）で分割。
    /////     </pre>
    ///// </summary>
    //std::vector<std::string_view> split(std::string_view line, char delim = ' ')
    //{
    //    return line
    //        // std::views::split は、区切り文字で分割して、分割された部分を range として返す。
    //        | std::views::split(delim)
    //        // std::views::transform は、range を std::string_view に変換するために使う。
    //        | std::views::transform([](auto&& r) -> std::string_view
    //            {
    //                // これが一番安全でモダン
    //                auto begin = r.begin();
    //                auto end = r.end();
    //                return { std::to_address(begin), std::to_address(end) };
    //            })
    //        // std::ranges::to<std::vector>() は、std::string_view のイテレーターを std::vector に変換するために使う。
    //        | std::ranges::to<std::vector>();
    //}
};
