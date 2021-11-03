
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node *next;
};
void create(int n,struct node *ptr)
{
    int el;
    struct node *tmp;
    for(int i=0;i<n;i++)
    {
     printf("Enter the element %d:",i+1);
     scanf("%d",&el);
     tmp=(struct node *)malloc(sizeof(struct node));
     tmp->e=el;
     tmp->next=NULL;
     ptr->next=tmp;
     ptr=tmp;
    }
}
void insert(int el,struct node *ptr)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node *));
    tmp->e=el;
    tmp->next=ptr->next;
    ptr->next=tmp;
}
int islast(struct node *ptr)
{
    return (ptr->next==NULL);
}
struct node *Findprev(int el,struct node *ptr)
{
    struct node *tmp;
    tmp=ptr;
    while(tmp->next!=NULL && tmp->next->e!=el)
    tmp=tmp->next;
    return tmp;
}
void delete(int el,struct node *p)
{
    struct node *tmp,*ptr;
    ptr=Findprev(el,p);
    if(islast(ptr))
    printf("\nElement not found");
    else
    {
        tmp=ptr->next;
        ptr->next=tmp->next;
        free(tmp);
    }
}
struct node *Find(int el,struct node *ptr)
{
    struct node *tmp;
    tmp=ptr;
    while(tmp!=NULL && tmp->e!=el)
    tmp=tmp->next;
    return tmp;
}
void print(struct node *p)
{
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d ",p->e);
    }
}
int main()
{
    int n,ch,el,pos;
    struct node *root,*p;
    root=(struct node *)malloc(sizeof(struct node));
    root->next=NULL;
    p=root;
    printf("\nEnter the no of elements:");
    scanf("%d",&n);
    create(n,p);
    while(1)
    {
        printf("\n\t\tMENU\n1.Insert\n2.Search\n3.Delete\n4.Print\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:
           {
               printf("\nEnter the element to be inserted:");
               scanf("%d",&el);
               printf("\nEnter the position at which element is to be inserted:");
               scanf("%d",&pos);
               p=root;
               for(int i=0;i<pos-1;i++)
               p=p->next;
               insert(el,p);
               break;
           }
           case 2:
           {
               int d;
               printf("\nEnter the element to be searched:");
               scanf("%d",&el);
               p=root;
               struct node *T=Find(el,p);
               if(T!=NULL)
               printf("\nElement found");
               else 
               printf("\nElement not found");
               break;
           }
           case 3:
           {
               printf("\nEnter the element to be deleted:");
               scanf("%d",&el);
               p=root;
               delete(el,p);
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


