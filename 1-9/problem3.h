#pragma once

#include <iostream>
#include <cmath>

namespace pr3
{

    void Run()
    {
        std::cout << "########## Problem3 ##########" << std::endl;

        constexpr auto val = 600851475143ull;
        constexpr auto upperBound = static_cast<uint64_t>( std::sqrt(val) );

        auto divides = [](const auto val, const auto divisor){
            return (val%divisor) == 0;
        };

        auto isPrime = [&](const uint64_t val) {

            const auto bound = static_cast<uint64_t>( std::sqrt(val) );
            for(uint64_t factor = 2; factor <= bound; ++factor){
                if(divides(val, factor)) return false;
            }
            return true;
        };

        auto v = upperBound;
        for(; v >= 2; v--)
        {
            if(!isPrime(v)) continue;
            if(!divides(val, v)) continue;
            break;
        }

        std::cout << "The result is: " << v << std::endl;
    }

}