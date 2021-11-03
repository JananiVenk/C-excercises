#include <stdio.h>
#include<ctype.h>
int stack[20],top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return stack[top--];
}
int main()
{
    int n1,n2,num,n3;
    char exp[100];
    char *e;
    printf("\nEnter the postfix expression:");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num=*e-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+':
                {
                    n3=n1+n2;
                    break;
                }
                case '-':
                {
                    n3=n1-n2;
                    break;
                }
                case '*':
                {
                    n3=n1*n2;
                    break;
                }
                case '/':
                {
                    n3=n1/n2;
                    break;
                }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression  = %d\n\n",pop());
    return 0;
}
