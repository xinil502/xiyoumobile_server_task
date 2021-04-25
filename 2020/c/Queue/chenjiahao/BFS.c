#include <stdio.h>
struct note
{
    int x;
    int y;
    int s;
};
char a[51][51];
int book[51][51];

int main(void)
{
    struct note que[2501];                               //队列
    int next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; //移动数组
    int head, tail;
    head = tail = 1;
    //读入数据
    int i, j, p, q, start_x, start_y, k, n, m;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%c", &a[i][j]);
    scanf("%d%d%d%d", &start_x, &start_y, &p, &q);
    //初始化信息
    que[tail].x = start_x;
    que[tail].y = start_y;
    que[tail].s = 0;
    tail++;
    book[start_x][start_y] = 1;

    int flage = 0, next_x, next_y;

    while (head < tail)
    {
        for (k = 0; k < 4; k++)
        {
            next_x = que[head].x + next[k][0];
            next_y = que[head].y + next[k][1];
            if (next_x < 1 || next_y < 1 || next_x > n || next_y > m)
                continue;
            if (a[next_x][next_y] == '-' && book[next_x][next_y] == 0)
            {
                book[next_x][next_y] = 1;
                que[tail].x = next_x;
                que[tail].y = next_y;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            if (next_x == p && next_y == q)
            {
                flage = 1;
                break;
            }
        }
        if (flage == 1)
            break;

        head++;
    }

    printf("%d", que[tail - 1].s);
    return 0;
}