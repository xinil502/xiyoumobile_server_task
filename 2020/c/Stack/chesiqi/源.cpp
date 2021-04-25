#include<stdio.h>
typedef struct node {
	int data[100];
	int index;
}Node;


//对栈进行初始化操作其实就是初始化栈顶指针
void init(Node *s) {
	s->index = -1;
}

void push(Node *s) {
	int n;
	while (1) {
		scanf_s("%d", &n);
		if (n == 0)
			break;
		(*s).index++;
		(*s).data[(*s).index] = n;
	}
}

int peek(Node s) {
	return s.data[s.index];
}

void pop(Node* s,int *e) {
	*e = (*s).data[(*s).index];
	(*s).index--;
}

void q(Node* p,Node *s) {
	int i;
	for (i = 0; i <= (*s).index; i++) {
		if (p->index == -1) {
			p->index++;
			p->data[p->index] = s->data[i];
		}
		else {
			if (s->data[i] > p->data[p->index]) {
				p->index++;
				p->data[p->index] = s->data[i];
			}
		}
	}
}

int main(void) {
	Node s,m;
	init(&m);
	init(&s);
	push(&s);
	int e;
	//pop(&s, &e);
	q(&m, &s);
	pop(&m, &e);
	printf("%d", e);
	return 0;
}