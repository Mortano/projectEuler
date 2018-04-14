#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include <algorithm>

namespace pr29
{

inline void Run()
{
    std::cout << "########## Problem29 ##########" << std::endl;

    //Figure out if 'v' can be written as a^b
    //auto factorize = [](auto v) -> std::optional<std::pair<int, int>> {
    //    auto threshold = (int)std::sqrt(v);
    //    for(auto a = threshold; a > 1; --a){
    //        for(auto b = 2; b <= threshold; ++b){
    //            auto pow = std::pow(a, b);
    //            if(pow > v) break;
    //            if(pow == v){
    //                return std::make_optional(std::make_pair(a, b));
    //            }
    //        }
    //    }
    //    return {};
    //};
    //
    //auto isEqualToLowerPower = [&](auto a, auto b){
    //    //Checks if a^b can be written as (a'^b')^b = a'^(b'*b) so that
    //    //b'*b <= 100
    //    auto factors = factorize(a);
    //    if(!factors) return false;
    //    return factors->second * b <= 100;
    //};
    //
    //auto sum = 0;
    //for(auto a = 2; a <= 100; ++a){
    //    for(auto b = 2; b <= 100; ++b){
    //        if(isEqualToLowerPower(a,b)) continue;
    //        ++sum;
    //    }
    //}

    std::vector<double> vals;
    for (auto a1 = 2; a1 <= 100; a1++)
    {        
        for (auto b1 = 2; b1 <= 100; b1++)
        {
            vals.push_back(b1 * std::log(a1));
        }
    }

    std::sort(vals.begin(), vals.end());

    constexpr auto Threshold = 0.000000001;
    auto sum = 0;
    for(size_t idx = 0; idx < vals.size() - 2; ++idx){
        auto v1 = vals[idx];
        auto v2 = vals[idx + 1];
        if(std::fabs(v1 - v2) <= Threshold) continue;
        ++sum;
    }

    std::cout << "The result is " << sum << std::endl;
}
};