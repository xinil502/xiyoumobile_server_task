#include<stdlib.h>
#define max 50

typedef struct Node {
	int data[max];
	int index;
}Node;
void init(Node *t)
{
	t->index=-1;
}
void push(Node *t) {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		t->index++;
		t->data[t->index] = n;
	}
}
int peek(Node *t) {
	return t->data[t->index];
}

void pop(Node* t,int *e) {
	*e = t->data[t->index];
	t->index--;
}
void getMin(Node *t,Node *q)
{
	int i;
	for(i=0;i<=t->index;i++)
	{
		if(q->index==-1)
		{
			q->index++;
			q->data[q->index]=t->data[i];
		}
		else
		{
			if(t->data[i]>q->data[q->index])
			{
				q->index++;
				q->data[q->index]=t->data[i];
			}
		}
	}
	
}

int main() {
	Node q,t;
	init(&q);
	init(&t);
	push(&t);
	getMin(&t, &q);
	int top;
	pop(&q, &top);
	printf("%d", top);
	return 0;
} 
