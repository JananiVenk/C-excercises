#include <stdio.h>
void merge(int a[],int temp[],int LP,int RP,int RE)
{
    int t,LE,num;
    t=LP;
    LE=RP-1;
    num=RE-LP+1;
    while(LP<=LE && RP<=RE)
    {
        if(a[LP]<=a[RP])
        temp[t++]=a[LP++];
        else
        temp[t++]=a[RP++];
    }
        while(LP<=LE)
        temp[t++]=a[LP++];
        while(RP<=RE)
        temp[t++]=a[RP++];
    for(int i=0;i<num;i++)
    {
        a[RE]=temp[RE];
        RE--;
    }
}
void mergesort(int a[],int temp[],int l,int r)
{
    if(l<r)
    {
       int mid=(l+r)/2;
       mergesort(a,temp,l,mid);
       mergesort(a,temp,mid+1,r);
       merge(a,temp,l,mid+1,r);
    }
    
}
int main()
{
    int arr[20],temp[20],i,n;
    printf("\nEnter the no of elements:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    mergesort(arr,temp,0,n-1);
    printf("\nAfter sorting:");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;

}