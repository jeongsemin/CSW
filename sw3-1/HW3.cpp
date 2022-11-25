#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include "block.h"
#include<conio.h>
#include"ChangeDir.h"
#include"Direction.h"

int block_id;
COORD curPos;

int main()
{
    RemoveCursor();
    int key;
    int block_move;
    srand((unsigned int)time(NULL));

    COORD Pos;

    //select random block
    block_id = (rand() % 7) * 4;
    showBlock(blockModel[block_id]);

    while (1)
    {
        key = _getch();
        char key2 = (char)key;
        
        switch (key2)
        {
        case 'q':
        {
            ShiftUp();
            ShiftLeft();
            break;
        }
        case 'w':
        {
            ShiftUp();
            break;
        }
        case 'e':
        {
            ShiftUp();
            ShiftRight();
        }
        case 'd':
        {
            ShiftRight();
            break;
        }
        case 'a':
        {
            ShiftLeft();
            break;
        }
        case 'z':
        {
            ShiftDown();
            ShiftLeft();
        }
        case 'x':
        {
            ShiftDown();
            break;
        }
        case 'c':
        {
            ShiftDown();
            ShiftRight();
            break;
        }
        case 'j':
        {
            RotateBlock();
            break;
        }
        case 'k':
        {
            RotateBlock();
            RotateBlock();
            break;
        }

        }
        
    }
    getchar();
    return 0;
}