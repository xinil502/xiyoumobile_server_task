#include<stdio.h>

typedef struct node {
	int x, y, step;
}Node;

int book[100][100];
int head, tail;
Node que[100];
int main(void) {
	int i,j;
	int a[100][100];
	int m, n;
	int next[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);//�����ǽ���Զ�������bookֵ��Ϊ1
			if (a[i][j] == 1) book[i][j] = 1;
		}
	}
	//��ʼλ�ã��յ�λ��
	int sx, sy, ex, ey, tx, ty;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	//��ʼλ�����
	que[tail].x = sx;
	que[tail].y = sy;
	tail++;
	book[sx][sy] = 1;

	while (tail != head) {
		//ö���ĸ�����
		for (i = 0; i <= 3; i++) {//�������һ������������жϻ᲻��Խ�磬Ҫ��Ҫ���
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if (tx >= m || tx < 0 || ty >= n || ty < 0)
				continue;
			if (book[tx][ty] == 0) {
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].step = que[head].step + 1;
				tail++;
				book[tx][ty] = 1;
			}

			if (tx == ex && ty == ey)
				break;
		}
		if (tx == ex && ty == ey)
			break;
		head++;
	}
	printf("%d", que[tail - 1].step);
	return 0;
}
