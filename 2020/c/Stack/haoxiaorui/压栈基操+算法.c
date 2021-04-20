#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int max=-999;
typedef struct Stack_Linklist{
    int data;
    struct Stack_Linklist *next;
}Node,*pNode;
typedef struct Stack{
    pNode pTop;
    pNode pBottom;
}Stack,*pStack;
void Initstack();//初始化栈
int Isempty();//判断是否为空栈
void Push();//压栈
int Pop();//出栈
int Gettop();//检测栈顶
void Traverse();//从栈顶遍历到栈底
void getmax();//获取最大值
int main(void)
{
    int val;
    Stack s1;
    Stack Max;
    Initstack(&s1);
    Initstack(&Max);
    if(Isempty(&s1))
    {
        printf("栈为空！\n");
    }
    else printf("栈不空！\n");
    //压栈
    printf("输入压栈元素:\n");
    scanf("%d",&val);
    Push(&s1,&Max,&val);

    printf("输入压栈元素:\n");
    scanf("%d",&val);
    Push(&s1,&Max,&val);

    printf("输入压栈元素:\n");
    scanf("%d",&val);
    Push(&s1,&Max,&val);

    //出栈 并且使用一个临时变量来存储 出栈的元素是什么
    if(Pop(&s1,&Max,&val))
       printf("出栈成功 出栈元素为:%d\n",val);
    else printf("栈为空\n");
    Traverse(&s1);
    getmax(Max);
    return 0;
}
//初始化,pBottom指向栈底，pTop指向栈顶,栈底元素next指针设置为空
void Initstack(pStack ps1)
{
    ps1->pBottom=(pNode)malloc(sizeof(Node));
    if(ps1->pBottom==NULL)
    {
        printf("动态内存分配失败\n");
        exit(-1);
    }
    else
    {
        ps1->pTop=ps1->pBottom;
        ps1->pBottom->next=NULL;
        return ;
    }
}
//判断栈是否为空 如果是空就返回1，不空则返回0
int Isempty(pStack ps1)
{
    if(ps1->pTop==ps1->pBottom)
    {
        return 1;
    }
    else
    return 0;
}
void Push(pStack ps1,pStack Max,int *pVal)
{
  if(max<*pVal)
  {
      max=*pVal;
  }
    pNode m;
    pNode p;
    p=ps1->pTop;
    ps1->pTop=(pNode)malloc(sizeof(Node));
    ps1->pTop->data=*pVal;
    ps1->pTop->next=p;
    m=Max->pTop;
     Max->pTop=(pNode)malloc(sizeof(Node));
    Max->pTop->data=max;
    Max->pTop->next=m;
    return ;
}
//出栈 用val返回出栈元素值，成功返回一 失败返回0
int Pop(pStack ps1,pStack Max,int *pVal)
{
    pNode p;
    pNode m;
    if(Isempty(ps1))
    return 0;
    else
    {
        p=ps1->pTop;
        *pVal=ps1->pTop->data;
        ps1->pTop=ps1->pTop->next;
        free(p);
         m=Max->pTop;
        
        Max->pTop=Max->pTop->next;
        free(m);
        return 1;
    }
}
int Gettop(pStack ps1,int *pVal)
{
    if(Isempty(ps1))
    return 0;
    else
    {
        *pVal=ps1->pTop->data;
        return 1;
    }
}
void Traverse(pStack ps1)
{
    pNode p;
    if(Isempty(ps1))
      printf("栈为空\n");
    else
    {
        printf("从栈顶遍历到栈底:");
        for(p=ps1->pTop;p!=ps1->pBottom;p=p->next)
             printf("%d ",p->data);
             printf("\n");
    }
}
void getmax(Stack Max)
{
    int data=Max.pTop->data;
    printf("%d\n",data);
}