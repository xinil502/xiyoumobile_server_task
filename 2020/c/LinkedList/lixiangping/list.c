#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct Node								
{
	elemtype data;
	struct Node *next;
}Node;
typedef struct List{
	Node *head;
	Node *last;
	int size;
}List;

int Init(List *L)						
{
	L->head=L->last=(Node *)malloc(sizeof(Node));
	L->last->next=NULL;
	L->size=0;
}

void firstAdd(List *L)		
{
	int data;
	
	while(scanf("%d",&data),data!=0)
	{
		Node *t=(Node*)malloc(sizeof(Node));
		t->data=data;
		t->next=NULL;
		t->next=L->head->next;
		L->head->next=t;
		L->size++;
		if(L->size==0)
		L->last=t;
	
	}
}

void lastAdd(List *L)			
{
int data;
	while(scanf("%d",&data),data!=0)
	{
		Node *t=(Node*)malloc(sizeof(Node));
		t->data=data;
		t->next=NULL;
		L->last->next=t;
		L->size++;
		L->last=t;
	
	}
}

int size(List *L)				
{
	return L->size;
}

Node* get(List *L, int i)			
{
	if(i==0)
	return L->head->next;
	Node *p=L->head->next;
	int j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	 } 
	 return p;
}


void removes(List *L, int i)				
{
	if(L->size==0)
	return ;
	Node *t=L->head;
	while(t->next)
	{
		if(t->next->data==i)
		{
			Node *s=t->next;
			t->next=s->next;
			free(s);
		}
		t=t->next;
	}
	
}



void Show(List *L)					//打印整个链表
{
	Node *t=L->head->next;
	while(t)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("end\n");
}

List insert(List *L, int x){
   List pre;
   List behind;
   Init(&pre);
   Init(&behind);
   Node *p=L->head->next;
    while(p){
        if(p->data<x){
            pre.last->next=p;
            pre.last=p;
            pre.size++;
        }
        else{
            behind.last->next=p;
            behind.last=p;
            behind.size++;
        }
        p=p->next;
    }
  pre.last->next=NULL;
  behind.last->next=NULL;
    pre.last->next=behind.head->next;
    return pre;
    
/*	LinkList t=head->next;
	LinkList s=head->next;
    while(t)
    {
    	if(t->data<x)
    	printf("%d ",t->data);	
		t=t->next;
	}
	while(s)
	{
		if(s->data>=x)
			printf("%d ",s->data);
			s=s->next;
	}
*/
}

int main()
{
	List L;
	Init(&L);
	lastAdd(&L);
	Show(&L);
	L=insert(&L,3);
	Show(&L);
	
	return 0;
}
