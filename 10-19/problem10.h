#pragma once

#include "util.h"

#include <iostream>

namespace pr10
{

    void Run()
    {
        std::cout << "########## Problem10 ##########" << std::endl;

        constexpr auto Limit = 2000000ull;

        uint64_t sum = 0;
        for(uint64_t i = 2; i < Limit; ++i){
            if(!util::isPrime(i)) continue;
            sum += i;
        }

        std::cout << "The result is: " << sum << std::endl;
    }

}