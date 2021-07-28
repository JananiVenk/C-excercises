#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    return a>b?a:b;
}
void lcs(char a[],char b[])
{
    int i=strlen(a);
    int j=strlen(b);
    int C[i+1][j+1];
    int r,c;
    printf("i=%d\nj=%d\n",i,j);
    printf("      ");
    
    
    for(c=0;c<j;c++)
    printf("%c ",b[c]);
    printf("\n");
    printf("   |");
    for(c=0;c<=j;c++)
    printf("%d|",c);
    printf("\n");
    for(r=0;r<=i;r++)
    {
        for(c=0;c<=j;c++)
        {
            if(r==0||c==0)
            C[r][c]=0;
            else if(a[r-1]==b[c-1])
            {
                C[r][c]=C[r-1][c-1]+1;
            }
            
            else
            C[r][c]=max(C[r-1][c],C[r][c-1]);
        }
    }
    for(r=0;r<=i;r++)
    {
        if(r==0)
        printf("  0|");
        else
        printf("%c %d|",a[r-1],r);
        for(c=0;c<=j;c++)
        {
             printf("%d|",C[r][c]);
        }
       
        printf("\n");
    }
    int l=C[i][j];
    int count=l;
    char lcs[l+2];
    lcs[l+1]='\0';
     while(i>0&&j>0)
     {
         if(a[i-1]==b[j-1])
        {
          lcs[l]=a[i-1];
          l--;
          i--;
          j--;
        }
        else if(C[i-1][j]>C[i][j-1])
        i--;
        else
        j--;   
      }
    printf("\nLCS is\n\n|");
    for(int x=0;x<=count;x++)
    printf("%d|",x+1);
    printf("\n|");
    for(int x=1;x<=count;x++)
    printf("%c|",lcs[x]);
    printf("\\0|");
}
int main()
{
    char s1[10],s2[10];
    printf("Enter string 1:");
    scanf("%s",s1);
    printf("\nEnter string 2:");
    scanf("%s",s2);
    lcs(s1,s2);
}