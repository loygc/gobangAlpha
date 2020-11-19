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

int cut_count = 0;
int search_count = 0;

using namespace std;

int nextStep[2];

int winPieceX[5];
int winPieceY[5];

struct shapeScore{
    int score;
    int shapeWin[5];
}shapeScores[18]={
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


doubla negamax(int is_ai, int depth; double alpha; double beta){
    
}


bool equalArray(int a[], int b[], int size){
    for(int i = 0; i < size; i++){
        if (a[i] == b[i]) {
            continue;
        }
        return false;
    }
    return true;
}

int** copyWithplayer(const int board[][15], int player){
    int** copyBoard = {0};
    if (player == 1) {
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                copyBoard[i][j] = board[i][j];
            }
        }
    }else if (player == 2){
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(board[i][j] == 2){
                    copyBoard[i][j] = 1;
                }else if(board[i][j] == 1){
                    copyBoard[i][j] == 2;
                }
            }
        }
    }

    return copyBoard;
}


int calcDirScore(int posX, int posY, const int board[][15]){
    
    int addScore = 0;
    //各个方向的得分 0:横向 1:纵向 2:反斜线 3:斜线
    int scoreDir[4] = {0};
    
    int fiveModel[5];
    
    
    //横向
    for(int i=posX-4; i<=posX;i++){
        if (i < 0) {
            continue;
        }else{
            for (int j=i; j < i+5; j++) {
                fiveModel[j-i] = board[j][posY];
            }
            for (int k = 0; k <= 18; k++) {
                if(equalArray(fiveModel, shapeScores[k].shapeWin, 5)){
                    scoreDir[0]+=shapeScores[k].score;
                };
            }
        }
    }
    
    
    //纵向
    for(int i=posY-4; i<=posY; i++){
        if (i < 0) {
            continue;
        }else{
            for (int j=i; j < i+5; j++) {
                fiveModel[j-i] = board[posX][j];
            }
            for (int k = 0; k <= 18; k++) {
                if(equalArray(fiveModel, shapeScores[k].shapeWin, 5)){
                    scoreDir[1]+=shapeScores[k].score;
                };
            }
        }
    }
    
    //反斜向
    for(int i=posX-4;i<=posX;i++){
        if (i < 0 || posY-(posX-i) < 0) {
            continue;
        }else{
            for(int j = i; j < i+5; j++){
                fiveModel[j-i] = board[i][posY-(posX-i)];
            }
            for (int k = 0; k <= 18; k++) {
                if(equalArray(fiveModel, shapeScores[k].shapeWin, 5)){
                    scoreDir[2]+=shapeScores[k].score;
                };
            }
        }
    }
    
    //斜向
    for(int i=posX+4;i<=posX;i++){
        if (i < 0 || posY-(i-posX) < 0) {
            continue;
        }else{
            for(int j = i; j < i+5; j++){
                fiveModel[j-i] = board[i][posY-(i-posX)];
            }
            for (int k = 0; k <= 18; k++) {
                if(equalArray(fiveModel, shapeScores[k].shapeWin, 5)){
                    scoreDir[3]+=shapeScores[k].score;
                };
            }
        }
    }
    
    for(int i=0; i < 4;i++){
        addScore += scoreDir[i];
    }

    return addScore;
}



int evaluation(){
    int totalScore = 0;
    return 0;
}





bool checkWin(const int piece[][15], int type) {
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


doubla negamax(const int data[][15], int is_ai, int depth; double alpha; double beta){
    if (checkWin(data, 1) || checkWin(data, 2) || depth == 0) {
        return evaluation(data,)
    }
    return alpha;
}

void AIwork(const int data[][15], int &x, int &y) {
    //第一步棋
    int cutCount = 0;
    int searchCount = 0;
//    for (int i = 0; i < 15; i++){
//        for (int j = 0; j < 15; j++){
//            cout << data[i][j];
//        }
//        cout << endl;
//    }
    
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (data[i][j] == 0) {
                x = i;
                y = j;
                cout << calcDirScore(5, 4, data) << endl;
                return;
            }
        }
    }
    
}





#endif /* alphaAlgo_h */
