#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include<stdio.h>
int a[100],b[100],c[100],x=0,y=0,z=0;
int fib(int n,char *c,int in,int k,int f)
 {

     if(n>=0)
     {
         if(n==0)
         {   c[in]=(char)f+'0';
               in++;
             c[in]='\0';
             printf("%s\n",c);
             in--;
             return 0;
         }

         if(f)
         {
          c[in]=(char)(k-n)+'0';
          k-=k-n;
          in++;
         }
          fib(n-1,c,in,k,1)+fib(n-2,c,in,k,2);
     }
     else
     {
         in--;
         return 0;
     }

}

int main()
{
    int n,i;
    printf("enter the no. of steps:");
    scanf("%d",&n);
    printf("no. of ways are:\n");
    char *c=(char*)malloc(sizeof(char)*20);
    fib(n,c,0,n,0);

return 0;
}
