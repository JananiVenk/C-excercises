#include <stdio.h>

int main()
{
    int a[20],n,i,j,temp,min;
    printf("\nEnter the no of elements:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
    printf("\nAfter sorting:");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
