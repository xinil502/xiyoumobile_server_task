#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define ElemType int

typedef struct QNode {
	ElemType val;
	struct QNode *next;
}QNode;

typedef struct Queue {
	QNode *head;
	QNode *tail;
}Queue;

//����ṹ�壬���е�Ԫ
typedef struct Qnode
{
	int x;
	int y;
	int s;//��ʾ���ǵڼ��������ߵ�
}Qnode;

void show(Queue *q);
void init(Queue *q);
void push(Queue *q, int key);
QNode* peek(Queue *q);
QNode* pop(Queue *q);
bool isEmpty(Queue *q);
int shortest();

int main() {
	Queue mq;
	init(&mq);
	int val;
	while (scanf_s("%d", &val), val != -1) {
		push(&mq, val);
	}

	show(&mq);
	for (int i = 0; i < 3; ++i) {
		pop(&mq);
	}
	show(&mq);
	//shortest();
	return 0;
}



void init(Queue *q) {
	q->head = q->tail = (QNode *)malloc(sizeof(QNode));
	q->tail->next = NULL;
}

void push(Queue *q, int key) {
	QNode *t = (QNode *)malloc(sizeof(QNode));
	t->val = key;
	t->next = NULL;
	q->tail->next = t;
	q->tail = t;
}

void show(Queue *q) {
	QNode *t = q->head->next;
	while (t) {
		printf("%d-->", t->val);
		t = t->next;
	}
	printf("NULL\n");
}


QNode* peek(Queue *q) {
	if (q->head->next) {
		return q->head->next;
	}
	else {
		return NULL;
	}
}


QNode* pop(Queue *q) {
	if (isEmpty(q)) {
		return NULL;
	}
	QNode *h = peek(q);
	if (q->head->next == q->tail) {
		q->tail = q->head;
	}
	QNode *p = q->head->next;
	q->head->next = p->next;
	free(p);
	return h;
}


bool isEmpty(Queue *q) {
	return q->head == q->tail;
}

int shortest() {
	Qnode que[2500];//��������
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	char a[50][50];
	int book[50][50] = {};//��������ֹ���ظ�
	int m, n, startx, starty, endx, endy, i, j, head, tail, tx, ty;
	printf("�������ͼ��С��\n");
	scanf_s("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		scanf_s("%s", a[i]);
	}
	printf("\n������������յ����꣺\n");
	scanf_s("%d %d %d %d", &startx, &starty, &endx, &endy);
	head = tail = 0;
	que[head].x = startx;
	que[head].y = starty;
	que[head].s = 0;
	book[startx][starty] = 1;
	tail++;
	int flage = 0;
	while (head < tail)
	{
		for (i = 0; i < 4; i++)//�ĸ�������չ
		{
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n)//�Ƿ�Խ��
			{
				continue;
			}
			if (a[tx][ty] == '.'&&book[tx][ty] == 0)//���������
			{
				//���
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].s = que[head].s + 1;//������һ
				book[tx][ty] = 1;//����Ѿ��߹�
				tail++;//��β����
			}
			if (tx == endx && ty == endy)//�ж��Ƿ��ߵ��յ�
			{
				flage = 1;
				break;
			}
		}
		if (flage == 1)
			break;
		head++;//��չ��ϵĵ����
	}

	printf("%d", que[tail - 1].s);//������ٵĲ���
	return 0;
}