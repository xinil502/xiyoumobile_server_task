#include<stdio.h>
#define max 10
struct note
{
	int x;
	int y;
	int s;
};

typedef struct {
	int data[max];
	int front;
	int rear;
}Queue;
//初始化 
void init(Queue &Q){
	Q.front=0;
	Q.rear=0;
} 
//判空 
bool isEmpty(Queue &Q){
	if(Q.front==Q.rear)
		return true;
	else 
		return false;
}
//入队 
bool push(Queue &Q,int e){
	if((Q.rear+1)%max==Q.front)	
		return false;
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%max;
	return true;
} 
//出队
bool pop(Queue &Q,int *e){
	if(isEmpty(Q))
		return false;
	*e=Q.data[Q.front];
	Q.front=(Q.front+1)%max;
	return true;
} 
//取头
bool peek(Queue &Q,int *e){
	if(isEmpty(Q))
		return false;
	*e=Q.data[Q.front];
	return true;
} 
//打印
void print(Queue &Q){
	int  t=Q.front;
	printf("**\n");
	while(Q.front!=Q.rear){
		printf("%d\n",Q.data[Q.front]);
		Q.front=(Q.front+1)%max;
	}
	printf("**\n");
	Q.front=t;
} 

int main()
{
	int a[50][50]={0};
	int book[50][50]={0};
	struct note que[2501];
	int next[4][2]={0,1,1,0,0,-1,-1,0};
	int n,m;
	scanf("%d%d",&n,&m);
	int p,q,tx,ty,flag;
	int head=1,tail=1;
	p=n+1;
	q=m+1;
	flag=0;
	que[tail].s=0;
	que[tail].x=1;
	que[tail].y=1;
	tail++;
	book[1][1]=1;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	while(head<tail)
	{
		for(int i=0;i<4;i++)
		{
			tx=que[head].x+next[i][0];
			ty=que[head].y+next[i][1];
			if(tx<1||tx>n||ty<1||ty>m)
				continue;
			if(book[tx][ty]==0&&a[tx][ty]==0)
			{
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].s=que[head].s+1;
				tail++;
			}
			if(tx==p&&ty==q)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)	break;
		head++;
	}
	printf("%d",que[tail-1].s);
}
