#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} LNode, *LinkList;

LinkList Creat_LinkList(int *values, int num)
{
    LinkList head = (LinkList)malloc(sizeof(LNode));
    LinkList tail = head, p;

    for (int i = 0; i < num; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = values[i];
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
    return head;
}

void Traverse_LinkList(LinkList head)
{
    if (!head)
        return;
    LinkList p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert_LinkList(LinkList *head, int pos, int val)
{
    LinkList p, s;
    p = *head;
    int j = 0;
    while (p && j < pos - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > pos)
        return;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = val;
    s->next = p->next;
    p->next = s;
}

void Delete_LinkList(LinkList *head, int pos, int *val)
{
    LinkList p, q;
    p = *head;
    int j = 0;
    while (p && j < pos - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > pos)
        return;
    q = p->next;
    p->next = q->next;
    *val = q->data;
    free(q);
}

void Seek_LinkList(LinkList head, int val)
{
    LinkList p = head->next;
    int i = 1;
    while (p && p->data != val)
    {
        p = p->next;
        ++i;
    }
    if (!p)
    {
        printf("未查到该元素\n");
        return;
    }
    // *pos = i;
    printf("%d", i);
}
int main(void)
{
    //元素读入数组
    int n;
    printf("请输入链表结点个数：\n");
    scanf("%d", &n);
    int *values = (int *)malloc(sizeof(int) * n);
    printf("%d", sizeof(values));
    printf("请输入链表的结点数据:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    //创建链表
    LinkList head;
    head = Creat_LinkList(values, n);

    //打印已创建的链表
    printf("打印<已创建>的链表\n");
    Traverse_LinkList(head);

    //插入操作
    printf("请输入插入的位置和插入的数据：\n");
    int pos, val;
    scanf("%d%d", &pos, &val);
    Insert_LinkList(&head, pos, val);
    printf("打印<插入元素>后的链表\n");
    Traverse_LinkList(head);

    //删除操作
    printf("请输入删除的位置：\n");
    scanf("%d", &pos);
    Delete_LinkList(&head, pos, &val);
    printf("打印<删除元素>后的链表\n");
    Traverse_LinkList(head);

    //查找元素位置
    printf("请输入查找的元素：\n");
    scanf("%d", &val);
    Seek_LinkList(head, val);

    return 0;
}