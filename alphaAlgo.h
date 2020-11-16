//
//  alphaAlgo.h
//  gobangAlpha
//
//  Created by Loyio Macbook on 2020/11/15.
//

#ifndef alphaAlgo_h
#define alphaAlgo_h

#define DEPTH 3;

#include <iostream>
#include <list>

using namespace std;

int aiList[100];

int playerList[100];

int allList[100];

int nextStep[2];

int winPieceX[5];
int winPieceY[5];

struct shapeScore{
    int score;
    int shapeWin[6];
}shapeScores[15]={
    {50, {0,1,1,0,0}},
    {50, {0,0,1,1,0}},
    {200, {1,1,0,1,0}},
    {500, {0,0,1,1,1}},
    {500, {1,1,1,0,0}},
    {5000, {0,1,1,1,0}},
    {5000, {1,0,1,1,0}},
    {5000, {0,1,0,1,1}},
    {5000, {1,1,0,1,0}},
    {5000, {0,1,1,0,1}},
    {5000, {1,1,1,0,1}},
    {5000, {1,1,0,1,1}},
    {5000, {1,0,1,1,1}},
    {5000, {1,1,1,1,0}},
    {5000, {0,1,1,1,1}},
    {50000, {0,1,1,1,1}},
    {50000, {1,1,1,1,0}},
    {99999999, {1,1,1,1,1}}
};




void AIwork(const int data[][15], int &x, int &y) {
    //第一步棋
    int cutCount = 0;
    int searchCount = 0;
    for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                if (data[i][j] == 0) {
                    x = i;
                    y = j;
                    return;
                }
    
}

int negamax(int depth, int alpha, int beta){
    return 0;
}



int evaluation(){
    int totalScore = 0;
    return 0;
}

int calcDirScore(int posX, int posY, int board[][15]){
    int addScore = 0;
    list<int> pos;
    //各个方向的得分
    int scoreDir[5];
    
    //横向
    for(int i=posX-4; i<=posX;i++){
        if (i < 0) {
            continue;
        }
    }
    
    
    
    
    
    return 0;
}

bool checkWin(int piece[][15], int type) {
    //对行进行循环判断
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 11; j++)
            if (piece[i][j] == type &&
                piece[i][j + 1] == type &&
                piece[i][j + 2] == type &&
                piece[i][j + 3] == type &&
                piece[i][j + 4] == type) {
                for (int win = 0; win < 5; win++) {
                    winPieceX[win] = i;
                    winPieceY[win] = j + win;
                }
                return true;
            }
    //对列进行循环判断
    for (int i2 = 0; i2 < 11; i2++)
        for (int j2 = 0; j2 < 15; j2++)
            if (piece[i2][j2] == type &&
                piece[i2 + 1][j2] == type &&
                piece[i2 + 2][j2] == type &&
                piece[i2 + 3][j2] == type &&
                piece[i2 + 4][j2] == type) {
                for (int win = 0; win < 5; win++) {
                    winPieceX[win] = i2 + win;
                    winPieceY[win] = j2;
                }
                return true;
            }
    //对反斜杠直线进行循环判断
    for (int i3 = 0; i3 < 11; i3++)
        for (int j3 = 0; j3 < 11; j3++)
            if (piece[i3][j3] == type &&
                piece[i3 + 1][j3 + 1] == type &&
                piece[i3 + 2][j3 + 2] == type &&
                piece[i3 + 3][j3 + 3] == type &&
                piece[i3 + 4][j3 + 4] == type) {
                for (int win = 0; win < 5; win++) {
                    winPieceX[win] = i3 + win;
                    winPieceY[win] = j3 + win;
                }
                return true;
            }
    //对斜杆直线进行循环判断
    for (int i4 = 0; i4 < 11; i4++)
        for (int j4 = 0; j4 < 11; j4++)
            if (piece[i4 + 4][j4] == type &&
                piece[i4 + 3][j4 + 1] == type &&
                piece[i4 + 2][j4 + 2] == type &&
                piece[i4 + 1][j4 + 3] == type &&
                piece[i4][j4 + 4] == type) {
                for (int win = 0; win < 5; win++) {
                    winPieceX[win] = i4 + 4 - win;
                    winPieceY[win] = j4 + win;
                }
                return true;
            }
    return false;
}







#endif /* alphaAlgo_h */
