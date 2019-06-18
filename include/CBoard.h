#ifndef CBOARD_H
#define CBOARD_H

#define ROW 4
#define COL 4

class CBoard
{
    public:
        CBoard();
        virtual ~CBoard();
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

#endif // CBOARD_H
