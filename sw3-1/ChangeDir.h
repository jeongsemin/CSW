#pragma once

void RemoveCursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
COORD GetCurrentCursorPos()
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;

    return curPoint;
}
void SetCurrentCursorPos(int x, int y)
{
    COORD position = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}
void showBlock(char blockInfo[4][4])
{
    int y, x;
    COORD curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);

            if (blockInfo[y][x] == 1)
                printf("¡á");
        }
    }

    SetCurrentCursorPos(curPos.X, curPos.Y);
}
void DeleteBlock(char blockInfo[4][4])
{
    int y, x;
    COORD curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);

            if (blockInfo[y][x] == 1)
                printf("  ");
        }
    }

    SetCurrentCursorPos(curPos.X, curPos.Y);
}
/*
COORD changeDir(COORD curPos, int num)
{
    //¿ì·Î 1Ä­
    if (num == 0)
    {
        curPos.X = curPos.X + 2;
        SetCurrentCursorPos(curPos.X, curPos.Y);
    }
    //ÁÂ·Î 1Ä­
    else if (num == 1)
    {
        if (curPos.X > 0)
        {
            curPos.X = curPos.X - 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
    }
    //À§·Î ÇÑÄ­
    else if (num == 2)
    {
        if (curPos.Y > 0)
        {
            curPos.Y = curPos.Y - 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
    }
    //¾Æ·¡·Î ÇÑÄ­
    else if (num == 3)
    {
        curPos.Y = curPos.Y + 2;
        SetCurrentCursorPos(curPos.X, curPos.Y);
    }
    //À§ÂÊ ¿À¸¥ÂÊ
    else if (num == 4)
    {
        if (curPos.Y != 0)
        {
            curPos.Y = curPos.Y - 2;
            curPos.X = curPos.X + 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
        else
        {
            curPos.Y = curPos.Y;
            curPos.X = curPos.X + 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
    }
    //¾Æ·¡ÂÊ ¿À¸¥ÂÊ
    else if (num == 5)
    {
        curPos.X = curPos.X + 2;
        curPos.Y = curPos.Y + 2;
        SetCurrentCursorPos(curPos.X, curPos.Y);
    }
    //À§ÂÊ ¿ÞÂÊ
    else if (num == 6)
    {
        if (curPos.X > 0 && curPos.Y > 0)
        {
            curPos.X = curPos.X - 2;
            curPos.Y = curPos.Y - 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
        else if (curPos.X > 0 && curPos.Y == 0)
        {
            curPos.X = curPos.X - 2;
            curPos.Y = curPos.Y;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
        else if (curPos.X == 0 && curPos.Y > 0)
        {
            curPos.X = curPos.X;
            curPos.Y = curPos.Y - 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
    }
    //¾Æ·¡ÂÊ ¿ÞÂÊ
    else if (num == 7)
    {
        if (curPos.X > 0)
        {
            curPos.X = curPos.X - 2;
            curPos.Y = curPos.Y + 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
        else
        {
            curPos.X = curPos.X;
            curPos.Y = curPos.Y + 2;
            SetCurrentCursorPos(curPos.X, curPos.Y);
        }
    }

    return curPos;
}
*/