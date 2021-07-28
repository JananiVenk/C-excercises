#include<stdio.h>
void main()
{
    int a,b,c;
    printf("\nEnter two numbers:");
    scanf("%d %d",&a,&b);
    c=a>b?a:b;
    printf("Greater of the two is %d\n",c);
}