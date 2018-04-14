#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

namespace pr16
{

inline void Run()
{
    std::cout << "########## Problem14 ##########" << std::endl;

    auto digitSum = [](const std::string& str){
        auto sum = 0;
        for(auto c : str){
            sum += (c - '0');
        }
        return sum;
    };

    auto mulByTwo = [](std::string& s){
        //Number is formatted left to right to make appending easier
        auto overflow = false;
        for(auto& c : s){
            auto val = c - '0';
            val *= 2;
            if(overflow){
                ++val;
                overflow = false;
            }
            if(val > 9){
                overflow = true;
                val -= 10;
            }
            c = '0' + val;
        }
        if(overflow){
            s += "1";
        }
    };

    std::string hugeNumber{"2"};
    for(auto i = 0; i < 999; ++i){
        mulByTwo(hugeNumber);
    }    

    auto result = digitSum(hugeNumber);

    std::cout << "The result is: " << result << std::endl;
}
}