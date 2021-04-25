#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, *LinkStackptr;

typedef struct
{
    LinkStackptr top;
    int count;
} LinkStack;

void InitStack(LinkStack *S)
{
    S->top = (LinkStackptr)malloc(sizeof(StackNode));
    if (!S->top)
        exit(-1);
    S->top = NULL;
    S->count = 0;
}

void ClearStack(LinkStack *S)
{
    LinkStackptr p, q;
    p = S->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
}

int StackEmpty(LinkStack S)
{
    if (S.count == 0)
        return 1;
    return 0;
}

int StackLength(LinkStack S)
{
    return S.count;
}

void GetTop(LinkStack S, int *e)
{
    if (S.top == NULL)
        return;
    *e = S.top->data;
}

void Push(LinkStack *S, int e)
{
    LinkStackptr p = (LinkStackptr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
}

void Pop(LinkStack *S, int *e)
{
    LinkStackptr p;
    if (StackEmpty(*S))
        return;
    *e = S->top->data;
    p = S->top;
    S->top = p->next;
    free(p);
    S->count--;
}

void StackTraverse(LinkStack S)
{
    LinkStackptr p;
    p = S.top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    LinkStack S;
    InitStack(&S);
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
    GetTop(S, &e);
    printf("%d\n", e);

    printf("ջ�ĳ��ȣ�\n");
    printf("%d\n", StackLength(S));

    printf("ջ�Ƿ�Ϊ�գ�\n");
    printf("%d(1���� 0����)", StackEmpty(S));
}