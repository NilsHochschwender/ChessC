#include <stdio.h>
#include <stdlib.h>
#define BB1 1
#define BB2 2
#define BB3 3
#define BB4 4
#define BB5 5
#define BB6 6
#define BB7 7
#define BB8 8
#define BT1 9
#define BT2 10
#define BL1 11
#define BL2 12
#define BS1 13
#define BS2 14
#define BD 15
#define BK 16
#define WB1 17
#define WB2 18
#define WB3 19
#define WB4 20
#define WB5 21
#define WB6 22
#define WB7 23
#define WB8 24
#define WT1 25
#define WT2 26
#define WL1 27
#define WL2 28
#define WS1 29
#define WS2 30
#define WD 31
#define WK 32

int getColor(int ID){
    // 0 is none, 1 is black, 2 is white
    if(ID == 0){
        return 0;
    } else if (BS1 <= ID && ID <= BK){
        return 1;
    } else if (WS1 <= ID && ID <= WK){
        return 2;
    }
}

int moveTower(int *playField, int TID){
    /*

        Tower can only move like this but is not limited to one cell at a time
          ^
          |
        <-T->
          ↓

    */
    int x,y;
    x = -1;
    y = -1;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (TID == playField[i][j]){
                x = j;
                y = i;
            }
        }
    }
    int TIDColor = getColor(TID)
    char direction = 'n';
    if (y == -1 || x == -1)
        return 0;
    puts("direction: R,U,D,L");
    while(sscanf("%c",&direction) != 1 && direction != 'r' && direction != 'R' && direction != 'u' && direction != 'U' && direction != 'd' && direction != 'D' && direction =! 'l' && direction && 'L')
        puts("try again");
    int dirct;
    switch (direction){
        case 'r':
        case 'R':
            dirct = 0;
            break;
        case 'd':
        case 'D':
            dirct = 2;
            break;
        case 'l':
        case 'L':
            dirct = 4;
            break;
        case 'u':
        case "U":
            dirct = 6;
            break;
    }
    int maxsteps;
    if (dirct == 0){
        for(int i = x + 1; i < 8; i++){
            int pFCol = getColor(playField[y][i]);
            if(pFCol != 0){
                if(TIDColor == pFCol){
                    maxsteps = i - x - 1;
                    break;
                } else {
                    maxsteps = i - x;
                    break;
                }
            } else if (i == 7){
                maxsteps = i - x;
                break;
            }
        }
    } else if (dirct == 2){ 
        for(int i = y + 1; i < 7; i++){
            int pFCol = getColor(playField[i][x]);
            if(pFCol != 0){
                if(TIDColor == pFCol){
                    maxsteps = i - y - 1;
                    break;
                } else {
                    maxsteps = i - y;
                    break;
                }
            } else if (i == 7){
                maxsteps = i - y;
                break;
            }
        }
    } else if (dirct == 4){
        for(int i = x - 1; i >= 0; i--){
            int pFCol = getColor(playField[y][i]);
            if(pFCol != 0){
                if(TIDColor == pFCol){
                    maxsteps = x - i - 1;
                    break;
                } else {
                    maxsteps = x - i;
                    break;
                }
            } else if (i == 7){
                maxsteps = x - 1;
                break;
            }
        }
    } else if (dirct == 6){ 
        for(int i = y - 1; i >= 0; i--){
            int pFCol = getColor(playField[i][x]);
            if(pFCol != 0){
                if(TIDColor == pFCol){
                    maxsteps = y - i - 1;
                    break;
                } else {
                    maxsteps = y - i;
                    break;
                }
            } else if (i == 0){
                maxsteps = y - i;
                break;
            }
        }
    }
    int steps = -1;
    printf("How many steps would you go? Max steps are %d", maxsteps);
    int err = scanf("%d", &steps);
    while(err == 0 && (steps == -1 || steps > maxsteps)){
        printf("Once more please a number smaller or equal to %d", maxsteps);
        err = scanf("%d", &steps);
    }
    if (dirct == 0){
        playField[x][y] = 0;
        int fig2 = playField[x][y+steps];
        
        if(fig2 != 0){

        }
    }

}

int main(void){
    int playField = {
        {BT1,BS1,BL1,BK,BD,BL2,BS2,BT2},
        {BB1,BB2,BB3,BB4,BB5,BB6,BB7,BB8},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {WB1,WB2,WB3,WB4,WB5,WB6,WB7,WB8},
        {WT1,WS1,WL1,WD,WK,WL2,WS2,WT2}
    };

}