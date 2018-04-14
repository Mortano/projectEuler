#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

namespace pr14
{

inline void Run()
{
    std::cout << "########## Problem14 ##########" << std::endl;

    auto nextCollatz = [](const uint64_t num){
        return (num&1) ? (3*num + 1) : (num / 2);
    };

    std::unordered_map<uint64_t, uint64_t> collatzLengths;
    auto calcCollatzLength = [&](const auto num){
        auto inMap = collatzLengths.find(num);
        if(inMap != collatzLengths.end()) return inMap->second;

        uint64_t length = 1;
        auto nextNum = num;
        while(nextNum != 1){
            nextNum = nextCollatz(nextNum);
            auto inMap = collatzLengths.find(nextNum);
            if(inMap != collatzLengths.end()){
                length += inMap->second;
                break;
            }
            ++length;
        }

        collatzLengths[num] = length;
        return length;
    };

    uint64_t maxVal = 0;
    uint64_t maxNum = 0;
    for(uint64_t i = 2; i < 1000000; ++i){
        auto score = calcCollatzLength(i);
        if(score <= maxVal) continue;
        maxVal = score;
        maxNum = i;
    }

    std::cout << "The result is: " << maxNum << std::endl;
}
}