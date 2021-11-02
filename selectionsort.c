#include <stdio.h>

int main()
{
    int a[20],n,i,j,temp,min;
    printf("\nEnter the no of elements:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("\nAfter sorting:");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}