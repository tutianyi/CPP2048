#include <stdlib.h>
#include <time.h>
#include "CLink.h"

CLink::CLink()
{
    h = (struct Head *)malloc(sizeof(struct Head));
    h->count = 0;
    h->next = NULL;
}

CLink::~CLink()
{
    struct Node *q,*p;
    p = h->next;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(h);
}

void CLink::InsertNode(int *n)
{
    struct Node *p,*q = (struct Node *)malloc(sizeof(struct Node));
    q->n = n;
    q->next = NULL;
    if(h->next==NULL)
        h->next = q;
    else
    {
        p = h->next;
        while(p->next!=NULL)
            p = p->next;
        p->next = q;
    }
    h->count++;
}

struct Node *CLink::FindNotZero(struct Node *p)
{
    while(p!=NULL && *(p->n)==0)
        p = p->next;
    return p;
}

struct Node *CLink::FindZero(struct Node *p)
{
    while(p!=NULL && *(p->n)!=0)
        p = p->next;
    return p;
}

int CLink::Merge()
{
    struct Node *p,*q;
    int moved=0;

    p = h->next;
    while(1)
    {
        p = FindNotZero(p);       if(p==NULL) break;
        q = FindNotZero(p->next); if(q==NULL) break;
        if(*(p->n)==*(q->n))
        {
            *(p->n) += *(q->n);
            *(q->n) = 0;
            p = p->next;
            moved = 1;
        }
        p = q;
    }
    return moved;
}

int CLink::RemoveBlank()
{
    struct Node *p,*q;
    int moved=0;

    p = h->next;
    while(1)
    {
        p = FindZero(p);          if(p==NULL) break;
        q = FindNotZero(p->next); if(q==NULL) break;
        *(p->n) = *(q->n);
        *(q->n) = 0;
        p = p->next;
        moved = 1;
    }
    return moved;
}

int CLink::Move()
{
    return Merge()+RemoveBlank();
}

void CLink::AddANumber()
{
    int i,r;
    struct Node *p;
    srand((unsigned)time(NULL));
    r = rand()%h->count;
    for(p = h->next,i=0; i<r; i++)
    {
        p = p->next;
    }
    *(p->n) = 2;
}

