#include <stdio.h>
#include<stdlib.h>
void insert(int a[],int e,int p,int n)
{
    for(int i=n-1;i>=p-1;i--)
    a[i+1]=a[i];
    a[p-1]=e;
}
int search(int a[],int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        return i+1;
    }
    return -1;
}
void delete(int a[],int p,int n)
{
    for(int i=p-1;i<n;i++)
    a[i]=a[i+1];
}
void print(int a[],int n)
{
    printf("\nArray elements:");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
int main()
{
    int a[20],n,ch;
    printf("\nElemet the no of array elements:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    while(1)
    {
        printf("\n\t\tMENU\n1.Insert\n2.Search\n3.Delete\n4.Print\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:
           {
               int el,pos;
               printf("\nEnter the element to be inserted:");
               scanf("%d",&el);
               printf("\nEnter the position at which element is to be inserted:");
               scanf("%d",&pos);
               insert(a,el,pos,n);
               n++;
               break;
           }
           case 2:
           {
               int d;
               printf("\nEnter the element to be searched:");
               scanf("%d",&d);
               int pos=search(a,d,n);
               if(pos==-1)
               printf("\nElement not found");
               else 
               printf("Position of the element:%d",pos);
               break;
           }
           case 3:
           {
               int x;
               printf("\nEnter the element to be deleted:");
               scanf("%d",&x);
               int pos=search(a,x,n);
               if(pos==-1)
               printf("\nElement not found");
               else 
               {
                delete(a,pos,n);
                n--; 
               }
               
               break;
           }
           case 4:
           {
               print(a,n);
               break;
           }
           case 5:
           exit(0);
           default:
           printf("\nInvalid choice");
        }
    }

    return 0;
}
