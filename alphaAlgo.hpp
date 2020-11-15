//
//  alphaAlgo.hpp
//  gobangAlpha
//
//  Created by Loyio Macbook on 2020/11/14.
//

#ifndef alphaAlgo_hpp
#define alphaAlgo_hpp

#include <iostream>

using namespace std;

void AIwork(const int data[][15], int &x, int &y) {
    //第一步棋
    
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (data[i][j] == 0) {
                x = i;
                y = j;
                return;
            }
        }
    }
}



#endif /* alphaAlgo_hpp */
