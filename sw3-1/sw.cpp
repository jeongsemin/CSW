#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include "block.h"
#include"ChangeDir.h"
#include"Direction.h"

#define LEFT 75
#define RIGHT 77
#define UP 72           //회전
#define Space 32
#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20
#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2
int score=0;
int block_id;
COORD curPos;
int speed=50;
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];

int main()
{
    RemoveCursor();
    speed = 10;
    srand((unsigned int)time(NULL));
    
    while (1) 
    {
        SetCurrentCursorPos((GBOARD_ORIGIN_X + GBOARD_WIDTH)*2, GBOARD_HEIGHT / 2);
        Print_score();

        block_id = (rand() % 7) * 4;

        ShowGBOARD();
        showBlock(blockModel[block_id]);
        if (IsGameOver())
            break;

        Sleep(1000);

        while (1) 
        {
            BlockDown();
            if (BlockDown() == 0)
            {
                AddBlockToBoard();
                RemoveFillupLine();
                break;
            }
            ProcessKeyInput();
        }
    }
    SetCurrentCursorPos((GBOARD_ORIGIN_X + GBOARD_WIDTH)/2, 0);
    
    puts("Game Over!!");
    getchar();
}
/*
int main()
{
    RemoveCursor();
    int block_move;
    int pos1, pos2;
    srand((unsigned int)time(NULL));
    
    COORD Pos;

    //select random block
    block_id = (rand() % 7) * 4;
    showBlock(blockModel[block_id]);
    Sleep(1000);

    //Move downward
    ShiftDown();
    Sleep(1000);

    //Move right-side;
    ShiftRight();
    Sleep(1000);

    //Rotate the block counterclockwise 4 times
    for (int i = 0; i < 4; i++)
    {
        RotateBlock();
        Sleep(1000);
    }
    
    //Move downward
    ShiftDown();
    Sleep(1000);

    //Move left-side
    ShiftLeft();
    Sleep(1000);

    //Move downward
    ShiftDown();
    Sleep(1000);

    getchar();
    return 0;
}
*/
/*
    while (1)
    {
        //블록 랜덤지정
        block_id = (rand() % 7) * 4;

        //시작위치 무작위
        pos1 = (rand() % 25);
        pos2 = (rand() % 25);

        curPos.X = pos1;
        curPos.Y = pos2;

        SetCurrentCursorPos(pos1, pos2);

        for (int i = 0; i < 20; i++) {
            //방향 무작위
            srand((unsigned int)time(NULL));
            block_move = (rand() % 8);

            //계속해서 회전
            showBlock(blockModel[block_id + (i % 4)]);
            Sleep(500);
            DeleteBlock(blockModel[block_id + (i % 4)]);


            curPos = changeDir(curPos, block_move);

            if (block_move == 0)
            {
                curPos.X += 1;
                SetCurrentCursorPos(curPos.X, curPos.Y);
            }

        }
    }*/

//블록의 출발점이 무작위로 계속 변경됨


//블록타입 무작위 결정
//이동하는 동안 계속 회전
//블록의 이동방향이 무작위로 변경됨