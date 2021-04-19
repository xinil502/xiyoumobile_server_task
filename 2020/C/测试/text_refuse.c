#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList;

LinkList Init_LinkList()
{
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

LinkList FirstAdd_LinkList(int *values, int num)
{
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    LinkList p = head, s;
    for (int i = 0; i < num; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = values[i];
        s->next = p->next;
        p = s;
    }
}

void LastAdd_LinkList(LinkList *head, int *values, int num)
{
    LinkList p, r = *head;
    for (int i = 0; i < num; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->next = NULL;
        p->data = values[i];
        r->next = p;
        r = p;
    }
}

int Get_LinkList(LinkList head, int pos)
{
    LinkList p = head;
    int j = 0;
    while (p && j < pos - 1)
    {
        p = p->next;
        j++;
    }
    return p->next->data;
}

void remove_LinkList(LinkList head, int e)
{
    LinkList p = head, q;
    while (p)
    {
        if (p->next->data != e)
        {
            p = p->next;
        }
        else
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
}

int Size_linkList(LinkList head)
{
    LinkList p = head;
    int j = 0;
    while (p)
    {
        p = p->next;
        ++j;
    }
    return j;
}
void Traverse_LinkList(LinkList head)
{
    LinkList p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void Move(LinkList *head, int x)
{
    LinkList p = *head;
    while (p && p->next->data < x)
    {
        p = p->next;
    }
    LinkList s = p->next, m;
    while (s && s->next)
    {
        if (s->next->data < x)
        {
            m = s->next;
            s->next = m->next;
            m->next = p->next;
            p->next = m;
            p = m;
        }
        else
        {
            s = s->next;
        }
    }
}

int main(void)
{
    printf("输入结点个数：\n");
    int n;
    scanf("%d", &n);
    printf("输入元素：\n");
    int nums[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int x;
    printf("请输入结点X：\n");
    scanf("%d", &x);
    LinkList head = Init_LinkList();
    LastAdd_LinkList(&head, nums, n);
    printf("移动前链表元素：\n");
    Traverse_LinkList(head);

    printf("移动后的链表：\n");
    Move(&head, x);
    Traverse_LinkList(head);
}