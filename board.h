#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#define ROW 4
#define COL 4

class board
{
    public:
        board();
        virtual ~board();
        void StartGame();
        void InsertANumber();
        void Output();
        int MoveLeft();
        int MoveRight();
        int MoveUp();
        int MoveDown();

    protected:

    private:
        int cells[ROW][COL];
        void OutputLine(int row);
};

#endif // BOARD_H
