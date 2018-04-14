#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <optional>
#include <tuple>

namespace pr4
{

    void Run()
    {
        std::cout << "########## Problem4 ##########" << std::endl;

        auto isPalindromic = [](auto val){
            std::stringstream ss;
            ss << val;
            auto str = ss.str();
            for(size_t idx = 0; idx < str.length()/2; ++idx){
                if(str[idx] != str[str.length() - idx - 1]) return false;
            }
            return true;
        };

        auto threeDigitFactors = [](auto val) -> std::optional<std::pair<uint32_t, uint32_t>> {            
            for(uint32_t factor = 100; factor < 1000; ++factor){
                if((val%factor) != 0) continue;
                auto div = val / factor;
                if(div < 100 || div >= 1000) continue;
                return std::make_optional(std::make_pair(factor, div));
            }
            return {};
        };

        constexpr uint32_t upperBound = 999*999;

        uint32_t result = 0;
        for(uint32_t v = upperBound; v > 0; v--)
        {
            if(!isPalindromic(v)) continue;
            auto factors = threeDigitFactors(v);
            if(!factors) continue;
            result = v;
            break;
        }

        std::cout << "The result is: " << result << std::endl;
    }

}