#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

namespace pr17
{

inline void Run()
{
    std::cout << "########## Problem17 ##########" << std::endl;

    const std::string oneDigit[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::string tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::string twoDigit[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const std::string houndred = "hundred";
    const std::string _and = "and";
    const std::string thousand = "onethousand";

    auto sumOneDigit = std::accumulate(std::begin(oneDigit), std::end(oneDigit), 0, [](auto accum, auto& str){
        return accum + str.length();
    });

    auto sumTens = std::accumulate(std::begin(tens), std::end(tens), 0, [](auto accum, auto& str){
        return accum + str.length();
    });

    auto sumTwoDigits = std::accumulate(std::begin(twoDigit), std::end(twoDigit), 0, [=](auto accum, auto& str){
        return accum + (10 * str.length()) + sumOneDigit;
    });

    auto sumHoundreds = std::accumulate(std::begin(oneDigit), std::end(oneDigit), 0, [&](auto accum, auto& str){
        return accum + (100 * (str.length() + houndred.length())) + (99 * _and.length()) + sumOneDigit + sumTens + sumTwoDigits;
    });

    auto sumThousand = thousand.length();

    auto result = sumOneDigit + sumTens + sumTwoDigits + sumHoundreds + sumThousand;

    std::cout << "The result is: " << result << std::endl;
}
}