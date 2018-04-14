#pragma once

#include <iostream>
#include <algorithm>

namespace pr12
{

inline void Run()
{
    std::cout << "########## Problem12 ##########" << std::endl;

    auto triangularNumber = [](uint64_t idx){
        return ((idx) * (idx+1)) / 2;
    };

    auto numFactors = [](uint64_t val){
        auto numFactors = 2;
        auto limit = val/2;
        for(uint64_t f = 2; f < limit; ++f){
            if((val % f) == 0) {
                numFactors += 2;
                limit = val/f;                    
            }
        }        
        //if((val % limit) == 0) ++numFactors;
        return numFactors;
    };

    uint64_t res = 0;
    for(uint64_t num = 2;; ++num){
        auto triNum = triangularNumber(num);
        auto factors = numFactors(triNum);
        std::cout << "The number " << triNum << " has " << factors << " factors" << std::endl;
        if(factors > 500){
            res = triNum;
            break;
        }
    }

    std::cout << "The result is: " << res << std::endl;
}
}