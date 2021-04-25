#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct Node								
{
	elemtype data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

int InitList(LinkList *L)						
{
	(*L) = (LinkList)malloc(sizeof(Node));
	if (!L)
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	(*L)->next = NULL;
	return 0;
}

void firstAdd(LinkList *L)		
{
	int i, n;
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	printf("请输入您要插入元素的个数：");
	scanf("%d", &n);
	printf("请输入你要插入的元素值(用空格隔开)：");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void lastAdd(LinkList *L)			
{
	int i, n;
	LinkList p,r;
	(*L) = (LinkList)malloc(sizeof(Node));
	r = *L;
	printf("请输入您要插入元素的个数：");
	scanf("%d", &n);
	printf("请输入你要插入的元素值(用空格隔开)：");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int size(LinkList *L)				
{
	int length = 0;
	LinkList p;
	p = (*L)->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

int get(LinkList L, int i, elemtype *e)			
{
	int j = 1;
	LinkList p;
	p = L->next;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		printf("查询不到该元素！\n");
		return 0;
	}
	*e = p->data;
	return 0;
}


void removes(LinkList *L, int i, elemtype *e)				
{
	LinkList p, q;
	int j = 1;
	p = *L;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		printf("删除元素失败！\n");
		return;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return;
}



void ShowList(LinkList *L)					//打印整个链表
{
	LinkList p;
	p = (*L)->next;
	if (p == NULL)
	{
		printf("这是一个空链表！\n");
	}
	printf("单链表");
	while (p)
	{
		printf(" -> %d", p->data);
		p = p->next;
	}
	printf("\n");
}
void insert(LinkList head, int x){
   /* Node*s=(Node *)malloc(sizeof(Node));
    Node*t=(Node *)malloc(sizeof(Node));
    Node*p1=s;
   Node*p2=t;
   
    while(head){
        if(head->data<x){
            p1->next=head;
            p1=p1->next;
        }
        else{
            p2->next=head;
            p2=p2->next;
        }
        head=head->next;
    }
  p2->next=NULL;
    p1->next=t->next->next;
    return s;
    */
	LinkList t=head->next;
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

}

int main()
{
	LinkList L;
	InitList(&L);
	int k,i;
	elemtype m ;
	lastAdd(&L);
	/*
	printf("单链表的长度为%d\n",size(&L));
	get(L, 5, &m);
	printf("得到的元素值为：%d\n", m);
	removes(&L, 3, &m);
	printf("删除元素后的");
	ShowList(&L);
	printf("删除的元素值为：%d\n", m);
	*/
	
	insert(L,3);
//	ShowList(&L);
	return 0;
}

