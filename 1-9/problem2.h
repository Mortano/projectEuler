#pragma once
#include <iostream>

namespace pr2{

    namespace{
        constexpr bool IsOdd(const uint64_t v){
            return (v&1) != 0;
        }

        constexpr auto Fibonacci(const uint64_t v){
            if(v==1) return 1;
            if(v==2) return 1;
            return Fibonacci(v-1) + Fibonacci(v-2);
        }

        constexpr auto FibSum(const uint64_t v = 1)
        {
            if(Fibonacci(v) >= 4000000) return 0;
            if(IsOdd(Fibonacci(v))) return FibSum(v+1);
            return Fibonacci(v) + FibSum(v+1);
        }
    }

    void Run(){
        std::cout << "########## Problem2 ##########" << std::endl;

        constexpr auto result = FibSum();

        std::cout << "The result is: " << result << std::endl;
    }


}