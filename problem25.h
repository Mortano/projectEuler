#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "util.h"

namespace pr25{

    inline void Run(){
        std::cout << "########## Problem25 ##########" << std::endl;

        auto fibonacciHasAtLeastDigits = [](auto n, auto digits){
            const auto logSqrt5 = 0.349485002168;
            const auto logPhi = 0.20898764025;
            auto leftHandSide = (n * logPhi) + std::log10(1 - std::pow(-0.381966011231, n));
            return leftHandSide >= (logSqrt5 + (digits - 1));
        };

        auto fibonacci = [](auto n){
            const auto phi = 1.6180339887;
            const auto psi = -0.6180339887;
            const auto sqrt5 = 2.2360679775;
            return (std::pow(phi, n) - std::pow(psi, n)) / sqrt5;
        };

        for(int n = 1;;++n){
            //std::cout << "Fibonacci " << n << ": " << fibonacci(n) << std::endl; 
            if(fibonacciHasAtLeastDigits(n, 1000)){
                std::cout << "The answer is " << n << std::endl;
                return;
            }
        }
    }

};