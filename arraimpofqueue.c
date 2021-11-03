
#include <stdio.h>
#include<stdlib.h>
int front,rear,size,a[20],cap;
void enqueue(int x)
{
    rear=rear%cap;
    a[rear]=x;
    rear++;
    size++;
}
int dequeue()
{
    front=front%cap;
    size--;
    return a[front++];
}
void print()
{
    int v=front;
    for(int i=0;i<size;i++)
    {
        v=v%cap;
        printf("%d ",a[v]);
        v++;
    }
}
int main()
{
    printf("\nEnter the capacity of stack:");
    scanf("%d",&cap);
    int ch,e;
    while(1)
    {
        printf("\n\t\tMENU\n1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                if(size==cap)
                printf("\nQueue is full");
                else
                {
                    printf("\nEnter the element to be pushed:");
                    scanf("%d",&e);
                    enqueue(e);
                }
                break;
            }
            case 2:
            {
                if(!size)
                printf("\nQueue is empty");
                else
                printf("%d",dequeue());
                break;
            }
            case 3:
            {
                if(!size)
                printf("\nQueue is empty");
                else
                print();
                break;
            }
            case 4:
            exit(0);
            default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}
