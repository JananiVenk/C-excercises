#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int e;
  struct tree *left;
  struct tree *right;
};
struct tree *create(int x)
{
        struct tree *T;
        T=(struct tree *)malloc(sizeof(struct tree));
        T->e=x;
        T->left=NULL;
        T->right=NULL;

    return T;
}
struct tree *Insert(int x,struct tree *T)
{
    if(T==NULL)
    {
        T=(struct tree *)malloc(sizeof(struct tree));
        T->e=x;
        T->left=NULL;
        T->right=NULL;
    }
    else if(x<T->e)
    T->left=Insert(x,T->left);
    else
    T->right=Insert(x,T->right);
    return T;
}
struct tree *Find(int x,struct tree *T)
{
    if(T==NULL)
    return NULL;
    else if(x<T->e)
    return Find(x,T->left);
    else if(x>T->e)
    return Find(x,T->right);
    else 
    return T;
}
void inorder(struct tree *p)
{
    
    if(p==NULL)return;
    inorder(p->left);
    printf("%d ",p->e);
    inorder(p->right);
}
void preorder(struct tree *p)
{
    
    if(p==NULL)return;
    printf("%d ",p->e);
    preorder(p->left);
    preorder(p->right);
}
void postorder(struct tree *p)
{   
    if(p==NULL)return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->e);
}
int main()
{
    struct tree *root;
    root=create(5);
    int el,ch;
    while(1)
    {
        printf("\n\t\tMENU\n1.Insert\n2.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
               printf("Enter the element to be inserted:");
               scanf("%d",&el);
               root=Insert(el,root);
               break;
            }
            case 2:
            {
                printf("\nInorder:");
                inorder(root);
                printf("\nPreorder:");
                preorder(root);
                printf("\nPostorder:");
                postorder(root);
                exit(0);
            }
            
            default:
            printf("\nInvalid choice");
        }
        
    }
    
    return 0;
}
