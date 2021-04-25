#pragma once
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