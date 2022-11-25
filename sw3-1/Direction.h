#pragma once
#include"ChangeDir.h"
#include"block.h"
extern int block_id;
extern COORD curPos;
extern int speed;
extern int score;
#define LEFT 75
#define RIGHT 77
#define UP 72           //È¸Àü
#define Space 32
#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20
#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

extern int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];

void Print_score()
{
    printf("Score : %d", score);
}
int DectectCollision(int posX, int posY, char blockModel[4][4])
{
    int x, y;
    int arrx = (posX - GBOARD_ORIGIN_X) / 2;
    int arry = (posY - GBOARD_ORIGIN_Y);
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (blockModel[y][x] == 1 && gameBoardInfo[arry + y][arrx + x] == 1)
                return 0;
        }
    }
    return 1;
}

void ShiftRight()
{
    if (!DectectCollision(curPos.X + 2, curPos.Y, blockModel[block_id])) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPos.X += 2;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    showBlock(blockModel[block_id]);
}
void ShiftLeft()
{
    if (!DectectCollision(curPos.X - 2, curPos.Y, blockModel[block_id])) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPos.X -= 2;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    showBlock(blockModel[block_id]);
}
void ShiftUp()
{
    DeleteBlock(blockModel[block_id]);
    curPos.Y -= 1;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    showBlock(blockModel[block_id]);
}
void ShiftDown()
{
    DeleteBlock(blockModel[block_id]);
    curPos.Y += 1;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    showBlock(blockModel[block_id]);
}
void RotateBlock()
{
    int block_senior;
    int block_rotate;

    block_senior = block_id - block_id % 4;
    block_rotate = block_senior + (block_id + 1) % 4;
    if (!DectectCollision(curPos.X, curPos.Y, blockModel[block_rotate])) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    block_id = block_rotate;
    showBlock(blockModel[block_id]);
}
int BlockDown()
{
    if (!DectectCollision(curPos.X, curPos.Y + 1, blockModel[block_id])) {
        return 0;
    }
    DeleteBlock(blockModel[block_id]);
    curPos.Y += 1;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    showBlock(blockModel[block_id]);
}
void RedrawBlocks(void)

{
    int x, y;
    int cursX, cursY;
    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            cursX = x * 2 + GBOARD_ORIGIN_X;
            cursY = y + GBOARD_ORIGIN_Y;
            SetCurrentCursorPos(cursX, cursY);
            if (gameBoardInfo[y][x] == 1)
            {
                printf("¡á");
            }
            else { printf("  "); }
        }
    }
}
void AddBlockToBoard() {
    int x, y, arrCurX, arrCurY;
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            arrCurX = (curPos.X - GBOARD_ORIGIN_X) / 2;
            arrCurY = curPos.Y - GBOARD_ORIGIN_Y;

            if (blockModel[block_id][y][x] == 1)
            {
                gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
            }
        }
    }
}

void RemoveFillupLine()
{
    int line, x, y;

    for (y = GBOARD_HEIGHT - 1; y > 0; y--)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            if (gameBoardInfo[y][x] != 1)
                break;
        }
        if (x == (GBOARD_WIDTH + 1))
        {
            for (line = 0; y - line > 0; line++)
            {
                memcpy(&gameBoardInfo[y - line -1][1], &gameBoardInfo[(y - line)][1], GBOARD_WIDTH * sizeof(int));
            }
        }
        if (x == (GBOARD_WIDTH + 1))
        {
            y++;
            score += 10;
        }
    }
    for (line = 0; y - line > 0; line++)
    {
        memcpy(&gameBoardInfo[y - line][1], &gameBoardInfo[y - line - 1][1], GBOARD_WIDTH * sizeof(int));
    }
    RedrawBlocks();
}

int IsGameOver()
{
    if (!DectectCollision(curPos.X, curPos.Y, blockModel[block_id]))
        return 1;

    return 0;
}

void SpaceDown()
{
    while (BlockDown());
}
void ProcessKeyInput()
{
    int key;
    for (int i = 0; i < 20; i++)
    {
        if (_kbhit() != 0)
        {
            key = _getch();
            switch (key)
            {
            case LEFT:
                ShiftLeft();
                break;
            case RIGHT:
                ShiftRight();
                break;
            case UP:
                RotateBlock();
                break;
            case Space:
                SpaceDown();
                break;
            }
        }
        Sleep(speed);
    }
}
void ShowGBOARD()
{
    int x, y;
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("¦¦");
        else
            printf("¤Ó");
    }
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + 2 * (GBOARD_WIDTH + 1), GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("¦¥");
        else
            printf("¤Ó");
    }

    for (x = 1; x <= GBOARD_WIDTH; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + 2 * x, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
        printf("¤Ñ");
    }
    SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
    curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
    curPos.Y = 0;

    for (int y = 0; y < GBOARD_HEIGHT + 1; y++)
    {
        gameBoardInfo[y][0] = gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
    }
    for (int x = 0; x < GBOARD_WIDTH + 2; x++)
    {
        gameBoardInfo[GBOARD_HEIGHT][x] = 1;
    }
}



void ReverseRotateBlock()
{
    int block_senior;
    DeleteBlock(blockModel[block_id]);
    block_senior = block_id - block_id % 4;
    block_id = block_senior + (block_id + 3) % 4;

    showBlock(blockModel[block_id]);
}
