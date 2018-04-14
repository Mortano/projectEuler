#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

namespace pr21{

    inline void Run(){
        std::cout << "########## Problem19 ##########" << std::endl;

        auto d_n = [](auto num){
            auto sum = 0;
            for(auto i = 1; i < num; ++i){
                if((num % i) == 0) sum += i;
            }
            return sum;
        };

        std::set<int> amicables;
        auto sum = 0;
        for(auto a = 2; a < 10000; ++a){      
            if(amicables.find(a) != amicables.end()) continue;      
            auto b = d_n(a);            
            auto d_b = d_n(b);
            if(d_b != a) continue;
            if(b == a) continue;
            sum += a;
            sum += b;
            amicables.emplace(a);
            amicables.emplace(b);            
        }

        std::cout << "The result is " << sum << std::endl;
    }

};