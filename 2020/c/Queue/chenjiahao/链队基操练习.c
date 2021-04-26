#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QMode *next;
} QNode, *Queueptr;

typedef struct
{
    Queueptr front, rear;
} LinkQueue;

void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (Queueptr)malloc(sizeof(QNode));
    if (!Q->front)
        exit(-1);
    Q->front->next = NULL;
}

void DestoryQueue(LinkQueue *Q)
{
    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

void ClearQueue(LinkQueue *Q)
{
    Queueptr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
}

int QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    return 0;
}

int QueueLength(LinkQueue Q)
{
    Queueptr p = Q.front;
    int i = 0;
    while ((Q.rear != p))
    {
        i++;
        p = p->next;
    }
    return i;
}

void GetHead(LinkQueue Q, int *e)
{
    Queueptr p;
    if (Q.front == Q.rear)
        return;
    p = Q.front->next;
    *e = p->data;
}

void EnQueue(LinkQueue *Q, int e)
{
    Queueptr p = (Queueptr)malloc(sizeof(QNode));
    if (!p)
        exit(-1);
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

void DeQueue(LinkQueue *Q, int *e)
{
    Queueptr p;
    if (Q->front == Q->rear)
        return;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
}

void QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p = Q.front->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
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