#include<stdlib.h>
#define max 50
/* 
typedef struct Node {
	int *data;
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
	
}*/ 

typedef struct {
    int *data;
    int top;
} Stack;


Stack* Create() {
    Stack *p=(Stack *)malloc(sizeof(Stack));
    p->data=(int *)malloc(max*sizeof(int));
    p->top=-1;
    return p;
}

void Push(Stack* p, int x) {
  if(p->top==max-1){
      
  }else if(p->top==-1){
      p->top++;
      p->data[p->top]=x;
      p->top++;
     p->data[p->top]=x;
  }else{
      int tmp=p->data[p->top];
      p->top++;
      p->data[p->top]=x;
      if(tmp>x){
        p->top++;
        p->data[p->top]=tmp;
      }else{
        p->top++;
        p->data[p->top]=x;
      }
  }
}

void Pop(Stack* p) {
  if(p->top==-1){
      
  }else{
      p->top--;
      p->top--;
  }
}

int Top(Stack* p) {
  if(p->top==-1){
      return;
  }
  return p->data[p->top-1];
  
}

int getMin(Stack* p) {
  return p->data[p->top];
}
//每一次执行push操作时，进行两次入栈，第一次入栈此元素，
//第二次入栈此时栈中最大的元素；执行pop操作与之相对

int main() {
/*	Node q,t;
	init(&q);
	init(&t);
	push(&t);
	getMin(&t, &q);
	int top;
	pop(&q, &top);
	printf("%d", top);
	return 0;
	*/
	int maxs;
	int x;
	 Stack *s;
	  s=Create();
	  while(scanf("%d",&x),x!=0)
	  {
	  	Push(s,x);
	   } 
	  
	 /*top= minStackTop(&s);
	 minStackPop(&s);*/
	 maxs=getMin(s);
	 printf("%d",maxs);
	 
	  
} 
