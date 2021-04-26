/*#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct QueueNode
{
	ElemType data;
	struct QueueNode *next;
}QueueNode;
typedef struct LinkQueue
{
	QueueNode *tail;
	QueueNode *front;
}LinkQueue;
void init(LinkQueue *s);
void push(LinkQueue *s,ElemType x);
void peek(LinkQueue *s,ElemType *x);
void pop(LinkQueue *s,ElemType *x);
void isEmpty(LinkQueue *s);
void show(LinkQueue *s);
void init(LinkQueue *Q)
{
	QueueNode *s=(QueueNode *)malloc(sizeof(QueueNode));
	Q->tail=Q->front=s;
	Q->tail->next=NULL;
}
void push(LinkQueue *Q, int x)
{
	QueueNode *s=(QueueNode*)malloc(sizeof(QueueNode));
	s->data=x;
	s->next=NULL;
	Q->tail->next=s;
	Q->tail=s;
}
void show(LinkQueue *Q)
{
QueueNode *t=Q->front->next;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("end");
}
void peek(LinkQueue *Q,ElemType *x)
{
	if(Q->tail==Q->front)
	{
		return;
	}
	else *x=Q->front->next->data;
}
void pop(LinkQueue *Q,ElemType *x)
{
	if(Q->tail==Q->front)
	return;
	QueueNode *t=Q->front->next;
	Q->front->next=t->next;
	*x=t->data;
	free(t);
	if(t==Q->front)
	Q->tail=Q->front;
}
void isEmpty(LinkQueue *Q)
{
	if(Q->tail==Q->front)
	{
		printf("队列已满");
		return; 
	}
	else 
	{
	printf("队列未满");
	return;	
	}
	 
}
//////////////////////////////
////////////////////////////////
////////////////////////////
int main()
{
	LinkQueue Q;
	int pk;
	int pk2;
	isEmpty(&Q);
	init(&Q);
	for(int i=1;i<=4;i++)
	{
		push(&Q,i);
	 } 
	 show(&Q);
	 peek(&Q,&pk);
	 printf("\n%d\n",pk);
	 pop(&Q,&pk2);
	 printf("\n%d\n",pk2);
	return 0;
}

*///队列 
#include<stdio.h>
struct node{
 int x;
 int y;
 int f;
 int s;
};
int main(){
 int a[100][100],book[100][100];
 struct node que[100];
 int head,tail;
 int startx,starty,endx,endy;
 int m,n,flag,i,j;
 int tx,ty;
 int next[4][2]={0,1,1,0,0,-1,-1,0};
 head=tail=1;
 scanf("%d %d",&m,&n);
 for(i=1;i<=m;i++){
 for(j=1;j<=n;j++){
 scanf("%d",&a[i][j]);
}
 }
 scanf("%d %d %d %d",&startx,&starty,&endx,&endy);
 book[startx][starty]=1;
 que[tail].x=startx;
 que[tail].y=starty;
 que[tail].f=0;
 que[tail].s=0;
 tail++;
 flag=0;
 while(head<tail){
 for(i=0;i<4;i++){
 tx=que[head].x+next[i][0];
 ty=que[head].y+next[i][1];
 if(tx<1||ty<1||tx>m||ty>n){
continue;
 }
 if(a[tx][ty]==0&&book[tx][ty]==0){
 book[tx][ty]==1;
 que[tail].x=tx;
 que[tail].y=ty;
 que[tail].f=head;
 que[tail].s=que[head].s+1;
 tail++;
 }
 if(tx==endx&&ty==endy){
 flag=1;
 break;
 }
 }
 if(flag==1){
break;
 }
 head++;

 }
if(flag==1){
 printf("%d",que[tail-1].s);
}
else{
 printf("无路径到达终点");
}
return 0;
}

