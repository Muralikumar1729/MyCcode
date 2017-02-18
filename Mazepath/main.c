#include <stdio.h>
#include <stdlib.h>
#include "stdio.h"
#include "stdlib.h"
#include<conio.h>

int  path(int i,int j,int **a,int n)  //finds path
{
	int c=0;
  if((i==n || i==-1) || (j==n || j==-1))
     return 0;
  if(i==n-1 && j==n-1 && a[i][j] )
  {
	  a[i][j]=5;
	  return 1;
  }
   if(a[i][j]==1 & a[i][j]!=3)
  {
  	a[i][j]=3;
	c=c ? 1 :path(i+1,j,a,n);
	c=	c ? 1 :path(i,j+1,a,n);
	c=c ? 1:path(i-1,j,a,n);
   c=c ? 1:	path(i,j-1,a,n);
   a[i][j]==3 ? a[i][j]=1:0;
   c?a[i][j]=5:0;
    return c;
   }
  else
	  return 0;
}




int check(int **a,int i,int j,int n) // used for displaying
{
	if(j+1==n )
   	return 0;
   	if(a[i][j+1]==5)
	{
		a[i][j+1]=2;
		return 1;
    }
	return 0;
}
int check2(int **a,int i, int j,int n) // used for displaying
{
  if(a[i][j]==2 | a[i][j]==5)
  {
	if(i+1 != n && a[i+1][j]==5)
		  return 1;
	  else
		  return 0;
  }
  else
	  return 0;
}
void display(int **a,int n,int c) // prints matrix
{
  int i,j,f =1;
   c ? printf("path present\n"):printf("path not present\n");
  for(i=0;i<n;i++)
  printf(" ---");
  printf("\n");
  for(i=0;i<n;i++)
  {
	for(j=0;j<n;j++)
	{
       if(j==0)
		printf("|");
         if(a[0][0] & j==0 & f & c)
		 {   f=0;
			 printf("\b ");
		 }
			 if(a[i][j]==5  | a[i][j]==2)
		{
		  if(check(a,i,j,n))
			  printf("    ");
		  else
			  printf("   |");
		}
		else
		printf(" %d |",a[i][j]);
	}
	if(i==n-1 & j==n & (a[n-1][n-1]==5 | a[n-1][n-1]==2) )
		printf("\b  ");
	printf("\n");
	for(j=0;j<n;j++)
	{
	  if(check2(a,i,j,n))
      printf("    ");
	  else
		  printf(" ---");
	}
    printf("\n");
   }
}


int main()
{
	int n,i,j,**a;
	printf("enter order n of square  matrix:");
	scanf("%d",&n);
     a=(int**)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
       a[i]=(int*)malloc(sizeof(int)*n);
      printf("enter %d elements of matrix only 0s and 1s:\n",n*n);
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	i=path(0,0,a,n);
	display(a,n,i);
	return 0;
}



