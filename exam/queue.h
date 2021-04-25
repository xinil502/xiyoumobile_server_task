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

//定义结构体，队列单元
typedef struct Qnode
{
	int x;
	int y;
	int s;//表示这是第几步可以走到
}Qnode;

void show(Queue *q);
void init(Queue *q);
void push(Queue *q, int key);
QNode* peek(Queue *q);
QNode* pop(Queue *q);
bool isEmpty(Queue *q);
int shortest();