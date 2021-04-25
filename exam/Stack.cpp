#include "Stack.h"

//初始化最大栈
int max = -2147483647;
void init(Stack *s) {
	s->top = s->bottom = (SNode *)malloc(sizeof(SNode));
	s->top->next = NULL;
}
void push(Stack *s, Stack *m, int key) {
	SNode *p = (SNode *)malloc(sizeof(SNode));
	p->val = key;
	p->next = NULL;
	s->top->next = p;
	s->top = p;
	push(m, key);
}

void push(Stack *m, int key) {
	if (key > max) {
		max = key;
		SNode *p = (SNode *)malloc(sizeof(SNode));
		p->val = key;
		p->next = NULL;
		m->top->next = p;
		m->top = p;
	}
}


SNode* peek(Stack *s) {
	//printf("Top = %d\n", s->top->val);
	return s->top;
}

SNode* pop(Stack *s, Stack* m) {
	bool is = isEmpty(s);
	if (is) {
		return NULL;
	}
	int max = s->top->val;
	SNode* p = peek(s);
	SNode *t = s->bottom;
	while (t->next != s->top) {
		if (t->val > max) {
			max = t->val;
		}
		t = t->next;
	}
	//每次出一次栈，则再次求出原栈的最大值和最大栈作比较，判断是否对最大栈做出调整！
	pop(m, max);
	free(t->next);
	t->next = NULL;
	s->top = t;
	return p;
}


void pop(Stack *m, int max) {
	//更新最大栈，如果原栈top的值不为max则说明原来的最大栈的max已经出了原栈，此处应该在最大栈中删除
	if (m->top->val != max) {
		SNode *t = m->bottom;
		while (t->next != m->top) {
			t = t->next;
		}
		free(t->next);
		t->next = NULL;
		m->top = t;
	}
}



bool isEmpty(Stack *s) {
	return  s->bottom == s->top;
}

void show(Stack *s) {
	SNode * p = s->bottom->next;
	while (p) {
		printf("%d-->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

void getMin(Stack *m) {
	if(m->top)
		printf("Max = %d\n", m->top->val);
	else {
		printf("空栈！\n");
	}
}