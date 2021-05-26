#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    int n1,n2,i,j;
    int num[10][10];
    scanf("%d",&n1);
    scanf("%d",&n2);
    /*
    num = (int**)malloc(sizeof(int*)*n1);
    for(i = 0;i < n2;++i)
        *num = (int*)malloc(sizeof(int)*n2);
        */
    for(i = 0;i < n1;++i)
    {
        for(j = 0;j < n2;++j)
        {
            scanf("%d",&num[i][j]);
        }
    }
    Linkqueue q;
    Node *p;
    Init(&q);
    Num s1;
    int i1,j1,couts1;
    createnum(&s1,num[0][0],0,0,0);
    Push(&q,s1);
    while(!isEmpty(&q))
    {
        p = Peek(&q);
        i1 = p->data.i;
        j1 = p->data.j;
        couts1 = p->data.couts;
        if(i1 == n1-1&&j1 == n2-1)
            break;
        Pop(&q);
        if(i1 != 0 && num[i1-1][j1] == 0)
        {
            createnum(&s1,num[i1-1][j1],i1-1,j1,couts1+1);
            Push(&q,s1);
        }
        if(i1 != n1-1&&num[i1+1][j1] == 0)
        {
            createnum(&s1,num[i1+1][j1],i1+1,j1,couts1+1);
            Push(&q,s1);
        }
        if(j1 != 0&&num[i1][j1-1] == 0)
        {
            createnum(&s1,num[i1][j1-1],i1,j1-1,couts1+1);
            Push(&q,s1);
        }
        if(j1 != n2-1&&num[i1][j1+1] == 0)
        {
            createnum(&s1,num[i1][j1+1],i1,j1+1,couts1+1);
            Push(&q,s1);
        }
    }
    printf("%d\n",couts1);
}



#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

#define ElemType Num

typedef struct _n
{
    int x;
    int i;
    int j;
    int couts;
}Num;

typedef struct _node
{
    ElemType data;
    struct _node *next;
}Node;

typedef struct _Linkqueue
{
    Node *fronts;
    Node *tail;
}Linkqueue;

void Init(Linkqueue *q);
void Push(Linkqueue *q,ElemType x);
void show(Linkqueue *q);
void Pop(Linkqueue *q);
Node* Peek(Linkqueue *q);
bool isEmpty(Linkqueue *q);
int Length(Linkqueue *q);
void createnum(Num *s1,int x,int i,int j,int couts);

#endif // LINKQUEUE_H_INCLUDED

#include "Queue.h"

void Init(Linkqueue *q)
{
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s != NULL);
    q->fronts = q->tail = s;
    q->tail->next = NULL;
}

void createnum(Num *s1,int x,int i,int j,int couts)
{
    s1->x = x;
    s1->i = i;
    s1->j = j;
    s1->couts = couts;
}

void Push(Linkqueue *q,ElemType x)
{
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;
    q->tail->next = s;
    q->tail = s;
}

void Pop(Linkqueue *q)
{
    if(q->fronts == q->tail)
        return;
    Node *p = q->fronts->next;
    q->fronts->next = p->next;
    free(p);
    if(p == q->tail)
        q->tail = q->fronts;
}

void show(Linkqueue *q)
{
    Node *p = q->fronts->next;
    while(p)
    {
        printf("%d-->",p->data);
        p = p->next;
    }
    printf("Tail\n");
}

int Length(Linkqueue *q)
{
    int num = 0;
    Node *p = q->fronts->next;
    while(p)
    {
        num++;
        p = p->next;
    }
    return num;
}

Node* Peek(Linkqueue *q)
{
    if(q->fronts == q->tail)
        return NULL;
    return q->fronts->next;
}
bool isEmpty(Linkqueue *q)
{
    if(q->fronts == q->tail)
        return true;
    return false;
}
