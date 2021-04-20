#include<stdio.h>
struct list{
    int x;
    int y;
    int s;
};
int book[51][51];
struct list que[2501];
int main(void)
{
    int a[51][51];
    int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int i,j,m,n,startx,starty,t,p,q,flag=0;
    int head=0;
    int tail=0;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);

    scanf("%d %d",&startx,&starty);
    scanf("%d %d",&p,&q);
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].s=0;
    tail++;
    
    while(head<tail)
    {
        int tx=que[head].x;int ty=que[head].y;
        for (int k = 0; k <= 3; k++)
        {
            tx+=next[k][0];
            ty+=next[k][1];
            if(tx>m || tx<1 ||ty>n ||ty<1)
            continue;
            if(a[tx][ty]==0 &&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].s=que[head].s+1;
                tail++;
                
            }
            if(tx==p &&ty ==q)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
        head++;
        
    }
    printf("%d",que[tail-1].s);
}