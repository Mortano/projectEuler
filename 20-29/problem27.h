#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "util.h"
#include "primes.h"

namespace pr27{

    inline void Run(){
        std::cout << "########## Problem27 ##########" << std::endl;

        auto quadraticFormula = [](auto n, auto a, auto b){
            return (n*n) + a*n + b;
        };

        auto numberOfPrimesGenerated = [](auto func){
            for(auto i = 0;;++i){
                auto v = func(i);
                if(v <= 0) return i;
                if(!util::isPrime(static_cast<uint64_t>(v))) return i;
            }
        };

        //Just brute force it, knowing that the factor b has to be a prime number
        auto longestStreak = 0;
        auto prodForLongestStreak = 0;
        for(auto a = -1000; a <= 1000; ++a){
            for(auto b : Primes_1k){
                auto negFormula = [=](auto v){
                    return quadraticFormula(v, a, -b);
                };
                auto posFormula = [=](auto v){
                    return quadraticFormula(v, a, b);
                };

                auto negLength = numberOfPrimesGenerated(negFormula);
                auto posLength = numberOfPrimesGenerated(posFormula);
                if(negLength > longestStreak){
                    longestStreak = negLength;
                    prodForLongestStreak = a * (-b);
                }
                if(posLength > longestStreak){
                    longestStreak = posLength;
                    prodForLongestStreak = a * b;
                }
            }
        }

        std::cout << "The result is " << prodForLongestStreak << std::endl;
    }

};