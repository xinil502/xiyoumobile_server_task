#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int top;
    int max;
} SqStack;

int IsEmpty_SqStack(SqStack S)
{
    if (S.top == -1)
        return 1;
    return 0;
}

void Init_SqStack(SqStack *S)
{
    S->top = -1;
    S->max = -99999;
}

void Push_SqStack(SqStack *S, SqStack *M, int e)
{
    if (S->top == MAXSIZE - 1)
        return;
    if (e > S->max)
        S->max = e;
    S->data[++S->top] = e;
    M->data[++M->top] = S->max;
}

void Pop_SqStack(SqStack *S, SqStack *M, int *e)
{
    if (!(IsEmpty_SqStack(*S)))
        return;
    M->top--;
    *e = S->data[S->top--];
}

void Peek_SqStack(SqStack *M, int *e)
{
    *e = M->data[M->top];
}

void GetMax(SqStack M, int *e)
{
    int m;
    Peek_SqStack(&M, &m);
    *e = m;
}

int main(void)
{
    int m;
    SqStack S, M;
    Init_SqStack(&S);
    M.top = -1;
    scanf("%d", &m);
    Push_SqStack(&S, &M, m);
    scanf("%d", &m);
    Push_SqStack(&S, &M, m);
    scanf("%d", &m);
    Push_SqStack(&S, &M, m);
    scanf("%d", &m);
    Push_SqStack(&S, &M, m);
    scanf("%d", &m);
    Push_SqStack(&S, &M, m);

    scanf("%d", &m);
    Pop_SqStack(&S, &M, &m);
    scanf("%d", &m);
    Pop_SqStack(&S, &M, &m);

    int max;
    GetMax(M, &max);
    printf("%d", max);
}