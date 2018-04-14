#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

namespace pr28{

    inline void Run(){
        std::cout << "########## Problem28 ##########" << std::endl;
        
        uint64_t sum = 1;        
        uint64_t nextNumber = 1;
        for(uint64_t level = 2; level <= 501; ++level){
            auto skip = (level - 1) * 2;
            for(auto i = 0; i < 4; ++i){
                nextNumber += skip;
                sum += nextNumber;
            }
        }

        std::cout << "The result is " << sum << std::endl;
    }

};