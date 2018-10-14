#include<stdio.h>
#define N 5


void Input_info (char name[N][8],int amount[N])
{
    for(int i=0;i<N;i++)
    {
        printf("Please write your name:");
        scanf("%s",name[i]);
        printf("Please write your amount:201804408");
        scanf("%2d",&amount[i]);
    }
    int j ;
        printf("  *name*\t\t\t*amount*\n");
    for(j=0;j<N;j++)
    {
       printf("%8s\t\t\t201804408%02d\n",name[j],amount[j]);
    }
}
int main()
{
   char name[N][8];
   int amount[N];
   Input_info(name,amount);
   return 0;
}

