#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <optional>
#include <tuple>
#include <numeric>
#include <string>

namespace pr9
{

    void Run()
    {
        std::cout << "########## Problem9 ##########" << std::endl;

        auto isPythagoreanTriplet = [](auto a, auto b, auto c){
            return (a*a + b*b) == (c*c);
        };

        auto result = [=](){
            for(auto c = 3; c < 1000; c++){
                for(auto b = 2; b < c; b++){
                    for(auto a = 1; a < b; a++){
                        if(!isPythagoreanTriplet(a,b,c)) continue;
                        if((a+b+c) != 1000) continue;
                        return a*b*c;
                    }
                }
            }
            return 0;
        }();

        std::cout << "The result is: " << result << std::endl;
    }

}