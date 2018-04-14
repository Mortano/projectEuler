#pragma once

#include <stdint.h>
#include <cmath>

namespace util{
    
    inline constexpr bool isPrime(const uint64_t n){
        if(n==2 || n==3) return true;
        if((n%2) == 0) return false;
        if((n%3) == 0) return false;
        const auto Limit = static_cast<uint64_t>(std::sqrt(n));
        uint64_t w = 2;
        for(uint64_t v = 5; v <= Limit;){
            if((n%v) == 0) return false;
            v += w;
            w = 6 - w;
        }
        return true;
    }

    /**
     * @brief Calculates all proper divisors (divisors excluding the number itself) of
     * the given number
     * 
     * @tparam Iter Iterator type
     * @param number Number to calc divisors for
     * @param out Output iterator to which the divisors will be written. Due to the algorithm,
     *            the divisors are _not_ written in order
     */
    template<typename Iter>
    inline constexpr void calcProperDivisors(const uint64_t number, Iter out){
        const auto Limit = static_cast<uint64_t>(std::sqrt(number));
        if(number < 2) return;
        *out++ = 1;
        for(uint64_t v = 2; v <= Limit; ++v){
            if((number%v) == 0) {
                auto upperDivisor = number / v;
                *out++ = v;
                if(upperDivisor != v) *out++ = upperDivisor;
            }
        }
    }

}