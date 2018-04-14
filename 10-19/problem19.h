#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "date.h"

namespace pr19{

    inline void Run(){
        std::cout << "########## Problem19 ##########" << std::endl;

        auto matches = 0;

        for(auto year = 1901; year < 2001; year++){
            for(auto month = 1; month <= 12; ++month){
                auto d = date::year{year}/date::month{month}/1;
                auto day = date::weekday{d};
                if(day == date::sun) ++matches;
            }
        }

        std::cout << "The result is " << matches << std::endl;
    }

};