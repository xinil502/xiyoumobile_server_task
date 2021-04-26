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
    printf("�������ʼ����ջԪ�ظ�����\n");
    int n;
    scanf("%d", &n);
    printf("�������ʼ����ջԪ�أ�\n");
    int m;
    for (int i = 0; i < n; i++) //��ջ
    {
        scanf("%d", &m);
        Push(&S, m);
    }
    printf("��ӡ��ʼ����ջԪ�أ�\n");
    StackTraverse(S);

    int e;
    printf("����ջ��Ԫ�أ�\n");
    Pop(&S, &e);
    printf("%d\n", e);

    printf("ջ��Ԫ�أ�\n");
    GetTop_SqStack(S, &e);
    printf("%d\n", e);

    printf("ջ�Ƿ�Ϊ�գ�");
    printf("%d(1���� 0����)", IsEmpty_SqStack(S));
}