#ifndef CLINK_H
#define CLINK_H

struct Node
{
    int *n;
    struct Node *next;
};

struct Head
{
    int count;
    struct Node *next;
};

class CLink
{
    public:
        CLink();
        virtual ~CLink();
        void InsertNode(int *p);
        void AddANumber();
        int Move();

    protected:

    private:
        struct Head *h;
        int Merge();
        int RemoveBlank();
        struct Node *FindNotZero(struct Node *p);
        struct Node *FindZero(struct Node *p);
};

#endif // CLINK_H
