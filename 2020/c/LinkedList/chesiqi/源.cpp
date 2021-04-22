#include<stdio.h>
#include<malloc.h>
typedef struct node {
	int data;
	struct node* next;
}Node;

struct node* init() {
	struct node* head,*s,*q;
	int n;
	head = (struct node*)malloc(sizeof(struct node));
	//head->next = NULL;
	scanf("%d", &n);
	head->data = n;
	q = head;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		s = (struct node*)malloc(sizeof(struct node));
		s->data = n;
		s->next = NULL;
		q->next = s;
		q = s;
	}
	q->next = NULL;
	return head;
}

void output(struct node* head) {
	struct node* p = head;
	while (p) {
		printf("%d", p->data);
		p = p->next;
	}
}

struct node* fenge(int x, struct node* head) {
	struct node* hmin =NULL;
	struct node* hmax = NULL;
	struct node* q = NULL, * hn = NULL, * hx = NULL;
	hn = hmin, hx = hmax;
	q = head;
	int flag = 0;
	int flag1 = 0;
	while (q!=NULL) {
		if (q->data >= x) {
			if (flag == 0) {
				hx = hmax = q;
				flag = 1;
			}
			else {
				hx->next = q;
				hx = q;
				
			}
			
		}
		else {
			if (flag1 == 0) {
				hn = hmin = q;
				flag1 = 1;
			}
			else {
				hn->next = q;
				hn = q;
				
			}
		}
		q = q->next;
	}
	hx->next = NULL;
	hn->next = hmax;
	return hmin;
}

int main(void) {
	struct node* head=NULL,*p;
	p=head = init();
	int x;
	scanf("%d", &x);
	int i;
	for (i = 0; i < x-1; i++)
		p = p->next;
	int m = p->data;
	struct node* q = fenge(m, head);
	output(q);
	return 0;
}