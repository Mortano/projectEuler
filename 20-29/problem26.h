#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "util.h"

namespace pr26{

    inline void Run(){
        std::cout << "########## Problem26 ##########" << std::endl;

        auto sequenceLength = [](auto div){
            //Computes length of fractional sequence of 1/div
            std::set<int> remainders;
            auto remainder = 10;
            auto seqLength = 0;
            while(true){
                remainder = remainder % div;
                if(!remainder) return 0;
                if(remainders.find(remainder) != remainders.end()) return seqLength;
                ++seqLength;
                remainders.insert(remainder);
                remainder *= 10;
            }
        };

        auto maxLength = 0;
        auto maxVal = 0;
        for(auto i = 1; i < 1000; ++i){
            auto l = sequenceLength(i);
            if(l > maxLength){
                maxLength = l;
                maxVal = i;
            }
        }

        std::cout << "The result is " << maxVal << std::endl;
    }

};