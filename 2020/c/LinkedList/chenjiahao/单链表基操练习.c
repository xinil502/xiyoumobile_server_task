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
        printf("δ�鵽��Ԫ��\n");
        return;
    }
    // *pos = i;
    printf("%d", i);
}
int main(void)
{
    //Ԫ�ض�������
    int n;
    printf("�����������������\n");
    scanf("%d", &n);
    int *values = (int *)malloc(sizeof(int) * n);
    printf("%d", sizeof(values));
    printf("����������Ľ������:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    //��������
    LinkList head;
    head = Creat_LinkList(values, n);

    //��ӡ�Ѵ���������
    printf("��ӡ<�Ѵ���>������\n");
    Traverse_LinkList(head);

    //�������
    printf("����������λ�úͲ�������ݣ�\n");
    int pos, val;
    scanf("%d%d", &pos, &val);
    Insert_LinkList(&head, pos, val);
    printf("��ӡ<����Ԫ��>�������\n");
    Traverse_LinkList(head);

    //ɾ������
    printf("������ɾ����λ�ã�\n");
    scanf("%d", &pos);
    Delete_LinkList(&head, pos, &val);
    printf("��ӡ<ɾ��Ԫ��>�������\n");
    Traverse_LinkList(head);

    //����Ԫ��λ��
    printf("��������ҵ�Ԫ�أ�\n");
    scanf("%d", &val);
    Seek_LinkList(head, val);

    return 0;
}