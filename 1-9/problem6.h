#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <optional>
#include <tuple>

namespace pr6
{

    void Run()
    {
        std::cout << "########## Problem4 ##########" << std::endl;

        constexpr uint64_t range = 100;

        auto sumOfSquares = [](uint64_t val){
            uint64_t ret = 0;
            for(uint64_t idx = 1; idx <= val; ++idx)
            {
                ret += (idx*idx);
            }
            return ret;
        };

        auto squareOfSum = [](uint64_t val){
            uint64_t sum = (val * (val+1)) / 2;
            return sum * sum;
        };

        auto res = squareOfSum(range) - sumOfSquares(range);

        std::cout << "The result is: " << res << std::endl;
    }

}