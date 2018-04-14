#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "util.h"

namespace pr24{

    inline void Run(){
        std::cout << "########## Problem24 ##########" << std::endl;

        int vals[] = {0,1,2,3,4,5,6,7,8,9};

        for(auto i = 1; i < 1000000; ++i){
            std::next_permutation(std::begin(vals), std::end(vals));
        }

        std::cout << "The answer is: ";
        for(auto v : vals) std::cout << v;
        std::cout << std::endl;
    }

};