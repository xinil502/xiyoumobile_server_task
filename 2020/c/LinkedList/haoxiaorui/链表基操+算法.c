#include<stdio.h>
#include<stdlib.h>
typedef struct nodelist{
    int data;
    struct nodelist *next;
}Node,*pNode;
pNode init(pNode L)
{
    L=(pNode)malloc(sizeof(Node));
    int n;
    scanf("%d",&n);
    L->data=n;
    L->next=NULL;
    return L;
}
pNode firstAdd(pNode L){
    pNode p,q=L;
    while(1){p=(pNode)malloc(sizeof(Node));
    int n;
    
    scanf("%d",&n);
    if(n==0)break;
    p->data=n;
    p->next=NULL;
    q->next=p;
    q=p;

    }
    return L;
}
pNode lastAdd(pNode L){
    pNode p,q=L;
     while(1){p=(pNode)malloc(sizeof(Node));
    int n;
    
    scanf("%d",&n);
    if(n==0)break;
    p->data=n;
    p->next=q;
    q=p;

    }
    return q;
}
int get(pNode L,int index)
{
    pNode p=L;
   for(int i=1;i<=index;i++)
   {
       p=p->next;
   }
   return p->data;
}
int remove1(pNode L,int index){
     pNode p=L;
   for(int i=1;i<index-1;i++)
   {
       p=p->next;
   }
   pNode q=p->next;
   int val=q->data;
   p->next=q->next;
   free(q);
   return val;

}
int size(pNode L){
   int cnt=0;
   pNode p=L;
   while(p!=NULL)
   {
       cnt++;
       p=p->next;
   }
   return cnt;
}
/*int main(){
    pNode L;
    L=init(L);
    //L=firstAdd(L);
    L=lastAdd(L);
    int a=get(L,1);
    int n=remove1(L,1);
    int c=size(L);
    printf("%d %d %d",a,n,c);
}*/
int main(){
    pNode L;
    L=init(L);
    L=firstAdd(L);
    int x;
    scanf("%d",&x);
    int a=size(L);
    pNode p=L;
    for(int i=0;i<a;i++)
    {
        if(p->data<x)
        printf("%d ",p->data);
        p=p->next;
    }
    p=L;
    for(int j=0;j<a;j++)
    {
         if(p->data>=x)
        printf("%d ",p->data);
        p=p->next;
    }
}