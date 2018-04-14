#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <optional>
#include <tuple>

namespace pr7
{

    void Run()
    {
        std::cout << "########## Problem7 ##########" << std::endl;

        auto isPrime = [](const uint64_t val){
            const auto limit = static_cast<uint64_t>(std::sqrt(val));
            for(uint64_t div = 2; div <= limit; ++div){
                if((val%div) == 0) return false;
            } 
            return true;
        };

        auto primeCount = 1;
        uint64_t res = 0;
        for(uint64_t i = 3;; i += 2){
            if(isPrime(i)) {
                ++primeCount;
                std::cout << "Prime count: " << primeCount << std::endl;
            }
            if(primeCount == 10001){
                res = i;
                break;
            }
        }

        std::cout << "The result is: " << res << std::endl;
    }

}