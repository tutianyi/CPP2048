#include "board.h"
#include "link.h"
#include <time.h>
#include <stdlib.h>

board::board()
{
    //ctor
}

board::~board()
{
    //dtor
}

void board::StartGame()
{
    int i,j;
    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            cells[i][j] = 0;
}

void board::OutputLine(int row)
{
    int j;
    for(j=0; j<COL; j++)
    {
        printf("©¦");
        if(cells[row][j]==0)
            printf("    ");
        else
            printf("%4d", cells[row][j]);
    }
    printf("©¦\n");
}

void board::Output()
{
    printf("©°©¤©¤©¤©¤©Ð©¤©¤©¤©¤©Ð©¤©¤©¤©¤©Ð©¤©¤©¤©¤©´\n");
    OutputLine(0);
    printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
    OutputLine(1);
    printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
    OutputLine(2);
    printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
    OutputLine(3);
    printf("©¸©¤©¤©¤©¤©Ø©¤©¤©¤©¤©Ø©¤©¤©¤©¤©Ø©¤©¤©¤©¤©¼\n");
}

void board::InsertANumber()
{
    int i,j;
    link l;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(cells[i][j]==0)
                l.InsertNode(&cells[i][j]);
        }
    }
    l.AddANumber();
    l.Release();
}

int board::MoveLeft()
{
    int i,j,moved=0;
    for(i=0;i<ROW;i++)
    {
        link l;
        for(j=0;j<COL;j++)
            l.InsertNode(&cells[i][j]);
        moved += l.Move();
        l.Release();
    }
    return moved;
}
int board::MoveRight()
{
    int i,j,moved=0;
    for(i=0;i<ROW;i++)
    {
        link l;
        for(j=COL-1;j>=0;j--)
            InsertNode(h, &cells[i][j]);
        moved += Move(h);
        Release(h);
    }
    return moved;
}
int board::MoveUp()
{
    int i,j,moved=0;
    struct Head *h;
    for(j=0;j<COL;j++)
    {
        h = NewList();
        for(i=0;i<ROW;i++)
            InsertNode(h, &cells[i][j]);
        moved += Move(h);
        Release(h);
    }
    return moved;
}
int board::MoveDown()
{
    int i,j,moved=0;
    struct Head *h;
    for(j=0;j<COL;j++)
    {
        h = NewList();
        for(i=ROW-1;i>=0;i--)
            InsertNode(h, &cells[i][j]);
        moved += Move(h);
        Release(h);
    }
    return moved;
}
