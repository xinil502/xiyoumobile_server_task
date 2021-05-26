#include "stack.h"


int main()
{
    Seqstack st,maxs;
    int v,n,x;
    InitStack(&st);
    InitStack(&maxs);
    while(1)
    {
        printf("1.push(ÊäÈë-1½ØÖÁ)  2.pop  3.getmax  4.show\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            while(scanf("%d",&x),x != -1)
            {
                if(Isempty(&st))
                Push(&maxs,x);
                else
                {
                    Peek(&maxs,&v);
                    if(x > v)
                        Push(&maxs,x);
                    else
                        Push(&maxs,v);
                }
                Push(&st,x);
            }
            show(&st);
            break;
        case 2:
            Pop(&st);
            Pop(&maxs);
            show(&st);
            break;
        case 3:
            Peek(&maxs,&v);
            printf("%d\n",v);
            break;
        case 4:
            show(&st);
            break;
        default:
            break;
        }
    }
    return 0;
}

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 8
#define STACK_INC_SIZE 3

typedef struct seqstack
{
    int *base;
    int capacity;
    int top;
}Seqstack;

bool Inc(Seqstack *s);

void InitStack(Seqstack *s);
bool Isempty(Seqstack *s);
bool Isfull(Seqstack *s);
void Push(Seqstack *s,int x);
void Pop(Seqstack *s);
bool Peek(Seqstack *s,int *v);
void show(Seqstack *s);

#endif // STACK_H_INCLUDED




#include "stack.h"

void InitStack(Seqstack *s)
{
    s->base = (int*)malloc(sizeof(int)*STACK_INIT_SIZE);
    assert(s->base != NULL);
    s->capacity = STACK_INIT_SIZE;
    s->top = 0;
}

bool Isempty(Seqstack *s)
{
    return s->top == 0;
}

bool Isfull(Seqstack *s)
{
    return s->top >= s->capacity;
}

bool Inc(Seqstack *s)
{
    int *newbase = (int*)realloc(s->base,sizeof(int)*(s->capacity + STACK_INC_SIZE));
    if(newbase == NULL)
    {
        printf("内存不足，无法申请空间！\n");
        return false;
    }
    s->base = newbase;
    s->capacity += STACK_INC_SIZE;
    return true;
}

void Push(Seqstack *s,int x)
{
    if(Isfull(s) && !Inc(s))
    {
        printf("栈空间已满,%d不能入栈！\n",x);
        return;
    }
    s->base[s->top++] = x;
}

void Pop(Seqstack *s)
{
    if(Isempty(s))
    {
        printf("栈空间已空，不能出栈！\n");
    }
    s->top--;
}

bool Peek(Seqstack *s,int *v)
{
    if(Isempty(s))
    {
        printf("栈空间已空，不能取栈顶元素！\n");
        return false;
    }
    *v = s->base[s->top-1];
    return true;
}

void show(Seqstack *s)
{
    int i;
    for(i = s->top-1;i >= 0;--i)
    {
        printf("%d   ",s->base[i]);
    }
    printf("\n");
}

