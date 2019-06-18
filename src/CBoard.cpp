#include "CBoard.h"
#include "CLink.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

CBoard::CBoard()
{
    //ctor
}

CBoard::~CBoard()
{
    //dtor
}

void CBoard::StartGame()
{
    int i,j;
    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            cells[i][j] = 0;
}

void CBoard::OutputLine(int row)
{
    int j;
    for(j=0; j<COL; j++)
    {
        printf("│");
        if(cells[row][j]==0)
            printf("    ");
        else
            printf("%4d", cells[row][j]);
    }
    printf("│\n");
}

void CBoard::Output()
{
    printf("┌────┬────┬────┬────┐\n");
    OutputLine(0);
    printf("├────┼────┼────┼────┤\n");
    OutputLine(1);
    printf("├────┼────┼────┼────┤\n");
    OutputLine(2);
    printf("├────┼────┼────┼────┤\n");
    OutputLine(3);
    printf("└────┴────┴────┴────┘\n");
}

void CBoard::InsertANumber()
{
    int i,j;
    CLink link;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(cells[i][j]==0)
                link.InsertNode(&cells[i][j]);
        }
    }
    link.AddANumber();
}

int CBoard::MoveLeft()
{
    int i,j,moved=0;
    for(i=0;i<ROW;i++)
    {
        CLink link;
        for(j=0;j<COL;j++)
            link.InsertNode(&cells[i][j]);
        moved += link.Move();
    }
    return moved;
}
int CBoard::MoveRight()
{
    int i,j,moved=0;
    for(i=0;i<ROW;i++)
    {
        CLink link;
        for(j=COL-1;j>=0;j--)
            link.InsertNode(&cells[i][j]);
        moved += link.Move();
    }
    return moved;
}
int CBoard::MoveUp()
{
    int i,j,moved=0;
    for(j=0;j<COL;j++)
    {
        CLink link;
        for(i=0;i<ROW;i++)
            link.InsertNode(&cells[i][j]);
        moved += link.Move();
    }
    return moved;
}
int CBoard::MoveDown()
{
    int i,j,moved=0;
    for(j=0;j<COL;j++)
    {
        CLink link;
        for(i=ROW-1;i>=0;i--)
            link.InsertNode(&cells[i][j]);
        moved += link.Move();
    }
    return moved;
}
