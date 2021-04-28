#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;

void init(Linklist &L){
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
}

void firstAdd(Linklist &L){
	Lnode *s;
	int x;
	scanf("%d",&x);
	while(x!=999){
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
}

void lastAdd(Linklist &L){
	Lnode *s,*r=L;
	int x;
	scanf("%d",&x);
	while(x!=999){
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;

}

Lnode * get(Linklist &L,int i,int *e){
	Lnode *p=L;
	int j=0;
	while(p->next!=NULL&&j<i){
		p=p->next;
		j++; 
	}
	*e=p->data;
	return p;
}

void remove(Linklist &L,int e){
	Lnode *p=L->next;
	while((p->next!=NULL)&&((p->next->data)!=e)){
		p=p->next;
	}
	Lnode *q=p->next;
	p->next=q->next;
	free(q);
}

int size(Linklist &L){
	Lnode *p=L;
	int i=0;
	while(p->next!=NULL){
		p=p->next;
		i++;
	}
	return i;
}

void print(Linklist &L){
	Lnode *p=L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

Lnode* fun(Linklist &p, int x) {
	Lnode* small =(Lnode*)malloc(sizeof(Lnode));
	Linklist smallHead = small;
	Lnode* large =(Lnode*)malloc(sizeof(Lnode));
	Linklist largeHead = large;
	while (p!=NULL) {
	    if (p->data< x) {
	        small->next = p;
	        small = small->next;
	    } else {
	        large->next = p;
	        large = large->next;
	    }
	    p= p->next;
	}
	large->next =NULL;
	small->next =largeHead->next;
	return smallHead;
}

int main()
{
	Linklist L;
	init(L);
	
	lastAdd(L);
	print(L);
	
//	firstAdd(L);
//	print(L);	
	
//	int i;
//	i=size(L);
//	printf("\n%d\n",i);

//	remove(L,6);
//	print(L);
	
	int x;
	scanf("%d",&x);
	Lnode *p=L->next;
	L=fun(p,x);
	print(L);
	
}
