#include "queue.h"

int main()
{
    List ps,p1,p2;
    //Node *s;
    int x;
    Init(&ps);
    Init(&p1);
    Init(&p2);
    while(scanf("%d",&x),x != -1)
    {
        lastadd(&ps,x);
    }
    scanf("%d",&x);
    Node *p = ps.first->next;
    while(p)
    {
        if(p->data < x)
            lastadd(&p1,p->data);
        else
            lastadd(&p2,p->data);
        p = p->next;
    }
    p1.last->next = p2.first->next;
    p1.last = p2.last;
    show(&p1);
    /*
    while(1)
    {
        printf("[1].firstadd(-1НижЙ) [2].lastadd  [3].remove  [4].size  [5].search\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            while(scanf("%d",&x),x != -1)
            {
                firstadd(&ps,x);
            }
            show(&ps);
            break;
        case 2:
            while(scanf("%d",&x),x != -1)
            {
                lastadd(&ps,x);
            }
            show(&ps);
            break;
        case 3:
            scanf("%d",&x);
            removes(&ps,x);
            show(&ps);
            break;
        case 4:
            printf("%d\n",sizes(&ps));
            break;
        case 5:
            scanf("%d",&x);
            s = get(&ps,x);
            printf("%d\n",s->data);
            break;
        default:
            break;
        }
    }
    */
    return 0;
}

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int data;
    struct _node *next;
}Node;

typedef struct _Linklist
{
    Node *first;
    Node *last;
    int sizes;
}List;

void Init(List *ps);
Node* buynode(int x);
void firstadd(List *ps,int x);
void lastadd(List *ps,int x);
Node* get(List *ps,int x);
Node* getpre(List *ps,int x);
void removes(List *ps,int x);
int sizes(List *ps);
void show(List *ps);

#endif // QUEUE_H_INCLUDED

#include "queue.h"


void Init(List *ps)
{
    Node *p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    ps->first = ps->last = p;
    ps->last->next = NULL;
    ps->sizes = 0;
}

Node* buynode(int x)
{
    Node *p = (Node*)malloc(sizeof(Node));
    assert(p != NULL);
    p->data = x;
    p->next = NULL;
    return p;
}

void firstadd(List *ps,int x)
{
    Node *p = buynode(x);
    p->next = ps->first->next;
    ps->first->next = p;
    if(ps->first == ps->last)
        ps->last = p;
    ps->sizes++;
}

void lastadd(List *ps,int x)
{
    Node *p = buynode(x);
    ps->last->next = p;
    p->next = NULL;
    ps->last = p;
    ps->sizes++;
}

Node* get(List *ps,int x)
{
    if(ps->first == ps->last)
        return NULL;
    Node *p = ps->first->next;
    while(p)
    {
        if(p->data == x)
            break;
        p = p->next;
    }
    if(p == NULL)
        return NULL;
    return p;
}

Node* getpre(List *ps,int x)
{
    if(ps->first == ps->last)
        return NULL;
    Node *p = ps->first;
    while(p->next)
    {
        if(p->next->data == x)
            break;
        p = p->next;
    }
    if(p->next == NULL)
        return NULL;
    return p;
}

void removes(List *ps,int x)
{
    Node *p = getpre(ps,x);
    if(p == NULL)
    {
        printf("未找到！\n");
        return;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    if(ps->last == q)
        ps->last = p;
    ps->sizes--;
}

int sizes(List *ps)
{
    return ps->sizes;
}

void show(List *ps)
{
    Node *p = ps->first->next;
    while(p)
    {
        printf("%d-->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}
