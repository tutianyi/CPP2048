#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "CBoard.h"
using namespace std;

int main()
{
    system("chcp 65001");
    int key1, key2, step=0, moved;
    CBoard board;
    board.StartGame();
    board.InsertANumber();
    board.InsertANumber();
    board.Output();
    while(1)
    {
        key1=_getch();
        if(key1)
        {
            key2=_getch();
        }
        switch(key2)
        {
        case 75: moved = board.MoveLeft();break;  // 按下的是方向键左
        case 77: moved = board.MoveRight();break; // 按下的是方向键右
        case 72: moved = board.MoveUp();break;    // 按下的是方向键上
        case 80: moved = board.MoveDown();break;  // 按下的是方向键下
        }
        if(moved)
        {
            board.InsertANumber();
            printf("Steps: %d\n", ++step);
            board.Output();
        }
    }
    return 0;
}
