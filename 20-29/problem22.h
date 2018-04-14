#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#include <unistd.h>

namespace pr22{

    inline void Run(){
        std::cout << "########## Problem22 ##########" << std::endl;

        auto score = [](const std::string& name){
            auto score = 0;
            for(auto c : name){
                score += (c - 'A') + 1;
            }
            return static_cast<size_t>(score);
        };

        std::ifstream file{"ProjectEuler/data/p022_names.txt"};
        if(!file.is_open()){
            std::cerr << "Could not find file " << "ProjectEuler/data/p022_names.txt" << std::endl;
            return;
        }

        std::vector<std::string> names;

        std::string line;
        while(std::getline(file, line, ',')){
            names.push_back(line.substr(1, line.length() - 2));
        }

        std::sort(names.begin(), names.end());

        size_t sum = 0;
        for(size_t idx = 0; idx < names.size(); ++idx){
            sum += score(names[idx]) * (idx+1);
        }

        std::cout << "The result is " << sum << std::endl;
    }

};