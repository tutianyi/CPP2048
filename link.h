#ifndef LINK_H
#define LINK_H

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

class link
{
    public:
        link();
        virtual ~link();
        void InsertNode(int *p);
        void Release();
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

#endif // LINK_H
