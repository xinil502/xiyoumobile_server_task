#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct stack{
	int top;
	int data[max];
}stack;

void init(stack &S){
	S.top=-1;
}

void push(stack &S,int e){
	if(S.top==max)
		return ;
	S.data[++S.top]=e;
}

void peek(stack &S,int *e){
	*e=S.data[S.top];
}

void pop(stack &S,stack &T,int *e){
	if(S.top==-1)	
		return ;
	*e=S.data[S.top--];
	T.top--;
}

bool isEmpty(stack &S){
	if(S.top==-1)
		return false;
	else 
		return true;
}

void print(stack &S){
	int t=S.top;
	printf("\n*");
	while(S.top!=-1){
		printf("\n%d\n",S.data[S.top--]);
	}
	printf("\n*");
	S.top=t;
}

int getmin(stack &T){
	int e;
	peek(T,&e);
	return e;
}

int main()
{
	stack S;
	init(S);
	stack T;
	init(T);
	int e;
	scanf("%d",&e);
	int Max=e;
	while(e!=999)	
	{
		if(e>Max)
			Max=e;
		push(S,e);
		push(T,Max);
		scanf("%d",&e);
	}
	print(S);
	pop(S,T,&e);
	printf("栈顶：%d\n",e);
	print(S);
	int x;
	x=getmin(T);
	printf("\n栈内最大值为：%d\n",x);
}
