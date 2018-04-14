#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

namespace pr18{

    struct Vec2{
        int x, y;
    };

    struct PathVertex{
        Vec2 pos;
        int sum;
    };
}

namespace std{
    template<>
    struct less<pr18::PathVertex>{
        bool operator()(const pr18::PathVertex& l, const pr18::PathVertex& r){
            return l.sum < r.sum;
        }
    };
}

namespace pr18{

    inline void Run(){
        const std::vector<std::vector<int>> triangle = {
            { 75 },
            { 95,64 },
            { 17,47,82 },
            { 18,35,87,10 },
            { 20,04,82,47,65 },
            { 19,01,23,75,03,34 },
            { 88,02,77,73,07,63,67 },
            { 99,65,04,28,06,16,70,92 },
            { 41,41,26,56,83,40,80,70,33 },
            { 41,48,72,33,47,32,37,16,94,29 },
            { 53,71,44,65,25,43,91,52,97,51,14 },
            { 70,11,33,28,77,73,17,78,39,68,17,57 },
            { 91,71,52,38,17,14,91,43,58,50,27,29,48 },
            { 63,66,04,68,89,53,67,30,73,16,69,87,40,31 },
            { 04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23 }
        };

        std::vector<std::vector<int>> revTriangle = triangle;
        std::reverse(revTriangle.begin(), revTriangle.end());

        std::cout << "########## Problem18 ##########" << std::endl;

        std::vector<std::vector<int>> bestPaths;

        //Backtracking algorithm. Start at the lowest level of the triangle and compute which path is the best
        //to get to each node at the lowest level. Then repeat at the next higher level by using the information
        //from the previous level
        for(auto& level : revTriangle){
            auto& bestAtCurrentLevel = bestPaths.emplace_back();

            if(bestPaths.size() == 1){
                //At the first level, the best vertex is just itself
                bestAtCurrentLevel = level;
            }
            else{
                bestAtCurrentLevel.reserve(level.size());
                auto& bestAtPrevLevel = bestPaths[bestPaths.size() - 2];
                for(size_t idx = 0; idx < level.size(); ++idx){
                    //For each node, find the best path that leads to this node by examining the
                    //two adjacent nodes on the previous level. Since we store the total cost to
                    //each node in 'bestPaths', this is a simple std::max
                    auto bestCost = std::max(bestAtPrevLevel[idx], bestAtPrevLevel[idx + 1]);
                    bestAtCurrentLevel.push_back(bestCost + level[idx]);
                }
            }
        }

        auto result = bestPaths.back().back();

        std::cout << "The result is " << result << std::endl;
    }

};