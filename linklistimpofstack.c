#include <stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node *next;
};
void push(int el,struct node *ptr)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->e=el;
    temp->next=ptr->next;
    ptr->next=temp;
}
void pop(struct node *p)
{
    struct node *temp;
    if(p->next==NULL)
    printf("\nStack underflow");
    else
    {
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
}
int Top(struct node *p)
{
    return p->next->e;
}
void print(struct node *ptr)
{
    if(ptr->next==NULL)
    printf("\nStack empty");
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            printf("%d",ptr->e);
        }
    }
}
int main()
{
    struct node *root,*p;
    root=(struct node *)malloc(sizeof(struct node));
    root->next=NULL;
    int ch,e;
    while(1)
    {
        printf("\n\t\tMENU\n1.Push\n2.Pop\n3.Display Top\n4.Print\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the element to be pushed:");
                scanf("%d",&e);
                p=root;
                push(e,p);
                break;
            }
            case 2:
            {
                p=root;
                pop(p);
                break;
            }
            case 3:
            {
                p=root;
                if(p->next==NULL)
                printf("\nStack underflow");
                else
                printf("\nTop:%d",Top(p));
                break;
            }
            case 4:
            {
                p=root;
                print(p);
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
