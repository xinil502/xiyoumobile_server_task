#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

int QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    return 0;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void GetHead(SqQueue Q, int *e)
{
    if (Q.front == Q.rear)
        return;
    *e = Q.data[Q.front];
}

void EnQueue(SqQueue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

void DeQueue(SqQueue *Q, int *e)
{
    if (Q->front == Q->rear)
        return;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}

void QueueTraverse(SqQueue Q)
{
    int i = Q.front;
    while ((i + Q.front) != Q.rear)
    {
        printf("%d ", Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main(void)
{
    SqQueue Q;
    InitQueue(&Q);
    printf("�������ʼ�������Ԫ�ظ�����\n");
    int n;
    scanf("%d", &n);
    printf("�������ʼ�������Ԫ�أ�\n");
    int m;
    for (int i = 0; i < n; i++) //��ջ
    {
        scanf("%d", &m);
        EnQueue(&Q, m);
    }
    printf("��ӡ��ʼ����ջԪ�أ�\n");
    QueueTraverse(Q);

    int e;
    printf("�����Ӷ�Ԫ�أ�\n");
    DeQueue(&Q, &e);
    printf("%d\n", e);

    printf("�Ӷ�Ԫ�أ�\n");
    GetHead(Q, &e);
    printf("%d\n", e);

    printf("ջ�Ƿ�Ϊ�գ�");
    printf("%d(1���� 0����)", QueueEmpty(Q));
}