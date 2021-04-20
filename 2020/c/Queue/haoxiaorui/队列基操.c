#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue * next;
}Queue,*pQueue;
typedef struct queuelist{
    pQueue front;
    pQueue rear;
}Qlist,*pQlist;
void init(pQlist L)
{
    
    pQueue q=(pQueue)malloc(sizeof(Queue));
    q->next=NULL;
    L->front=L->rear=q;

}
int Isempty(pQlist L)
{
    if(L->rear ==L->front)
    return 1;
    return 0;
}
void push(pQlist L,int val)
{
    pQueue p=(pQueue)malloc(sizeof(Queue));
    
    p->data=val;
    p->next=NULL;
    L->rear->next=p;
    L->rear=p;
    
}
int pop(pQlist L){
    if(Isempty(L))
    return -1;
    pQueue p=L->front->next;
    int val=p->data;
    L->front=p->next;
    if(p->next==NULL)
    L->front=L->rear;
    free(p);
    return val;
}
int main(){
    Qlist L;
    init(&L);
    int val;
    scanf("%d",&val);
    push(&L,val);
    scanf("%d",&val);
    push(&L,val);
    int del=pop(&L);
    printf("%d",del);
}