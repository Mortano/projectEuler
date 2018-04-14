#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <optional>
#include <tuple>

namespace pr5
{

    void Run()
    {
        std::cout << "########## Problem4 ##########" << std::endl;

        //Evenly divisible by 1-20, we only have to check the following:
        //20, 19, 18, 17, 16, 15, 14, 13, 12, 11

        auto matchesDivisibleCriterion = [](auto val) {
            for(uint32_t v = 11; v <= 20; ++v)
            {
                if((val % v) != 0) return false;
            }
            return true;
        };

        auto res = [&](){
            uint32_t val = 20;
            while(!matchesDivisibleCriterion(val)){
                ++val;
            }
            return val;
        }();

        std::cout << "The result is: " << res << std::endl;
    }

}