#include<stdio.h>
int main(void)
{
    int a;
    scanf("%d",&a);
    double b=a;
    printf("%g",b);
    int c=sizeof(double);
    int d=sizeof(int);
    printf("%d %d",c,d);
    return 0;
}
