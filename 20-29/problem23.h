#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "util.h"

namespace pr23{

    inline void Run(){
        std::cout << "########## Problem23 ##########" << std::endl;

        auto isAbundantNumer = [](auto num){
            struct SumIterator{
                explicit SumIterator(int& sum) : sum(sum) {}

                SumIterator& operator++() { return *this; }
                SumIterator& operator++(int) { return *this; }
                SumIterator& operator*() { return *this; }

                SumIterator& operator=(int num) { sum += num; }

                int& sum;
            };

            int sum = 0;
            SumIterator iter{sum};
            util::calcProperDivisors(num, iter);
            return iter.sum > num;
        };

        constexpr auto Threshold = 28123;

        std::set<int> abundantNumbers;
        for(int i = 12; i <= Threshold; ++i){
            if(!isAbundantNumer(i)) continue;
            abundantNumbers.insert(i);
        }

        auto isSumOfTwoAbundantNumbers = [&](auto num){
            for(auto abundantNumber : abundantNumbers){
                if(abundantNumber >= num) break;
                auto diff = num - abundantNumber;
                if(abundantNumbers.find(diff) != abundantNumbers.end()) return true;
            }
            return false;
        };

        uint64_t sum = 0;
        for(int val = 1; val <= Threshold; ++val){
            if(isSumOfTwoAbundantNumbers(val)) continue;
            sum += static_cast<uint64_t>(val);
        }

        std::cout << "The result is " << sum << std::endl;
    }

};