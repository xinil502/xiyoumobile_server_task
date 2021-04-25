#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int val;
	struct Node *next;
}Node;

typedef struct List {
	Node *head;
	Node *last;
	int size;
}List;

void init(List *list);
void firstAdd(List *list);
void lastAdd(List *list);
Node* get(List *list, int pos);
void remove(List *list, int key);
int size(List *list);
void show(List *list);
List ff(List *list, int key);
