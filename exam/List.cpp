#include "List.h"

void init(List *list) {
	list->last = list->head = (Node *)malloc(sizeof(Node));
	list->last->next = NULL;
	list->size = 0;
}

void firstAdd(List *list) {
	printf("ͷ�巨\n");
	int val;
	while (scanf_s("%d", &val), val != -1) {
		Node *t = (Node *)malloc(sizeof(Node));
		t->val = val;
		t->next = NULL;
		t->next = list->head->next;
		list->head->next = t;
		if (list->size == 0) {
			list->last = t;
		}
		list->size++;
	}
}


void lastAdd(List *list) {
	printf("β�巨\n");
	int val;
	while (scanf_s("%d", &val), val != -1) {
		Node *t = (Node *)malloc(sizeof(Node));
		t->val = val;
		t->next = NULL;
		list->last->next = t;
		list->last = t;
		list->size++;
	}
}

Node* get(List *list, int pos) {
	if (pos == 0) {
		return list->head->next;
	}
	Node *p = list->head->next;
	int i = 0;
	while (p != NULL &&i < pos - 1) {
		p = p->next;
		i++;
	}
	return p;

}

void remove(List *list, int key) {
	if (list->size == 0) {
		return;
	}
	Node *t = list->head;
	while (t->next) {
		if (t->next->val == key) {
			Node *p = t->next;
			t->next = p->next;
			free(p);
		}
		t = t->next;
	}
}

int size(List *list) {
	return list->size;
}

void show(List *list) {
	Node *t = list->head->next;
	while (t) {
		printf("%d-->", t->val);
		t = t->next;
	}
	printf("NULL\n");
}

List ff(List *list, int key) {
	List a;
	List b;
	init(&a);
	init(&b);
	Node *p = list->head->next;
	while (p) {
		if (p->val < key) {
			a.last->next = p;
			a.last = p;
			a.size++;
		}
		else {
			b.last->next = p;
			b.last = p;
			b.size++;
		}
		p = p->next;
	}
	a.last->next = NULL;
	b.last->next = NULL;
	a.last->next = b.head->next;
	return a;
}
