#pragma once

#include <iostream>

namespace pr1{

    inline void Run() {
        std::cout << "########## Problem1 ##########" << std::endl;
        
        auto isDivisibleBy = [](auto val, auto divisor) {
            return (val % divisor) == 0;
        };
        auto divBy3Or5 = [&](auto val) {
            return isDivisibleBy(val, 3) || isDivisibleBy(val, 5);
        };

        auto sum = 0;
        for(auto idx = 3; idx < 1000; ++idx)
        {
            if(!divBy3Or5(idx)) continue;
            sum += idx;
        }

        std::cout << "The result is: " << sum << std::endl;
    }

}