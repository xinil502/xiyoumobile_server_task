#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct SNode {
	int val;
	struct SNode *next;
}SNode;

typedef struct Stack {
	SNode *top;
	SNode *bottom;
}Stack;

void show(Stack *s);
void init(Stack *s);
void push(Stack *s, Stack *m, int key);
void push(Stack *m, int key);
SNode* peek(Stack *s);
SNode* pop(Stack *s, Stack *m);
void pop(Stack *m, int max);
bool isEmpty(Stack *s);
void getMin(Stack *s);