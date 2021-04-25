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
    printf("请输入初始化入队列元素个数：\n");
    int n;
    scanf("%d", &n);
    printf("请输入初始化入队列元素：\n");
    int m;
    for (int i = 0; i < n; i++) //入栈
    {
        scanf("%d", &m);
        EnQueue(&Q, m);
    }
    printf("打印初始化入栈元素：\n");
    QueueTraverse(Q);

    int e;
    printf("弹出队顶元素：\n");
    DeQueue(&Q, &e);
    printf("%d\n", e);

    printf("队顶元素：\n");
    GetHead(Q, &e);
    printf("%d\n", e);

    printf("栈是否为空：");
    printf("%d(1：空 0：否)", QueueEmpty(Q));
}