#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct Node
{
    int data[MAXSIZE];
    int top;
} SqStack;

void Init_SqStack(SqStack *S)
{
    S->top = -1;
}

void Clear_SqStack(SqStack *S)
{
    S->top = -1;
}

int IsEmpty_SqStack(SqStack S)
{
    if (S.top == -1)
        return 1;
    return 0;
}

int SqStack_length(SqStack S)
{
    return S.top + 1;
}

void GetTop_SqStack(SqStack S, int *e)
{
    if (S.top == -1)
        return;
    *e = S.data[S.top];
}

void Push(SqStack *S, int e)
{
    if (S->top == MAXSIZE - 1)
        return;
    S->data[++S->top] = e;
}

void Pop(SqStack *S, int *e)
{
    if (S->top == -1)
        return;
    *e = S->data[S->top--];
}
void StackTraverse(SqStack S)
{
    int i = S.top;
    while (i >= 0)
    {
        printf("%d ", S.data[i]);
        i--;
    }
    printf("\n");
}

int main(void)
{
    SqStack S;
    Init_SqStack(&S);
    printf("请输入初始化入栈元素个数：\n");
    int n;
    scanf("%d", &n);
    printf("请输入初始化入栈元素：\n");
    int m;
    for (int i = 0; i < n; i++) //入栈
    {
        scanf("%d", &m);
        Push(&S, m);
    }
    printf("打印初始化入栈元素：\n");
    StackTraverse(S);

    int e;
    printf("弹出栈顶元素：\n");
    Pop(&S, &e);
    printf("%d\n", e);

    printf("栈顶元素：\n");
    GetTop_SqStack(S, &e);
    printf("%d\n", e);

    printf("栈是否为空：");
    printf("%d(1：空 0：否)", IsEmpty_SqStack(S));
}