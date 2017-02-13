// tic tac toe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "stdlib.h"
#include "conio.h"
#define setdisp   printf("\n\t\t");
#define clear system("cls");
#define matchc(x) printf("\t\t   match %d",x)
//#define setinp printf(" 1 | 2 | 3\n 4 | 5 | 6\n 7 | 8 | 9");
#define hypen printf("--- --- ---")
typedef struct player
{
  char name[25];
  char c;
  int win;
};
void setinp()
{
  setdisp;
  printf(" 1 | 2 | 3 ");
  setdisp;hypen;setdisp;
  printf(" 4 | 5 | 6");
    setdisp;hypen;setdisp;
  printf(" 7 | 8 | 9");
}
player * getdetails()
{
	player* temp=(player*)malloc(sizeof(player));
	fflush(stdin);
	printf("enter name:");
	scanf("%s",temp->name);
	fflush(stdin);
	printf("enter character:");
	fflush(stdin);
	scanf("%c",&temp->c);
	temp->win=0;
	return temp;
}
void printmatrix(char *a[])
{
  int i,j;
  for(i=0;i<3;i++)
  {
	  for(j=0;j<3;j++)
		  printf("%c",a[i][j]);
  printf("\n");
  }
}
void init(char **a)
{
  for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
		  a[i][j]=' ';
}
void matrixdisp(char *a[])
{
  int i,j;
  for(i=0;i<3;i++)
  {
    setdisp;
	  for(j=0;j<3;j++)
	printf(" %c |",a[i][j]);
	printf("\b ");
	setdisp;
	if (i<2)
	hypen;
	
	//printf("\n");
  }
}
void miscel(char **a,int match)
{
	clear;
	matchc(match);
 	setdisp;
	setinp();
	setdisp;
	matrixdisp(a);
}

int checker(char **a,player *p)
{
    if(a[0][0]==p->c && a[0][1]==p->c && a[0][2]==p->c)
		return ++p->win;
	else if(a[0][0]==p->c && a[1][0]==p->c && a[2][0]==p->c)
		return ++p->win;
	else if(a[0][0]==p->c && a[1][1]==p->c && a[2][2]==p->c)
		return ++p->win;
	else if(a[0][1]==p->c && a[1][1]==p->c && a[2][1]==p->c)
		return ++p->win;
	else if(a[0][2]==p->c && a[1][2]==p->c && a[2][2]==p->c)
		return ++p->win;
	else if(a[1][0]==p->c && a[1][1]==p->c && a[1][2]==p->c)
		return ++p->win;
	else if(a[2][0]==p->c && a[2][1]==p->c && a[2][2]==p->c)
		return ++p->win;
	else if(a[2][0]==p->c && a[1][1]==p->c && a[0][2]==p->c)
		return ++p->win;
	else return 0;

}

void setter(char a,char **mat,char p)
{
  switch(a)
  {
  case '1':mat[0][0]=p;break;
  case '2':mat[0][1]=p;break;
  case '3':mat[0][2]=p;break;
  case '4':mat[1][0]=p;break;
  case '5':mat[1][1]=p;break;
  case '6':mat[1][2]=p;break;
  case '7':mat[2][0]=p;break;
  case '8':mat[2][1]=p;break;
  case '9':mat[2][2]=p;break;
  }
}
char reader(char **a,player *p,bool *hash,int match)
{
	char c;
	miscel(a,match);
	do
	{
		
printf("\n\t%s selection:",p->name);
		fflush(stdin);
		scanf("%c",&c);
	}
	while(hash[c-'0']);
	hash[c-'0']=true;
	return c;
}
int nextmatch(char **a,player *p,player *q,int match)
{
	miscel(a,match);
	char c;
	bool *hash=(bool*)calloc(10,sizeof(bool));
	int flag=1,flag2=0;
	for(int count=0;count<9;count++)
	{
			  miscel(a,match);
			  if(flag)
			  {
					c=reader(a,p,hash,match);				 
				  flag=0;
					setter(c,a,p->c);
				  flag2=checker(a,p);	
			  }
			  else
			  {
				  c=reader(a,q,hash,match);

			  	 	flag=1;
				setter(c,a,q->c);				
				flag2=checker(a,q);
			  }
			if(flag2)
			{
				miscel(a,match);
				printf("\n\t\t    match completed\n");
				printf("\t\t   %s won",flag2==p->win?p->name:q->name);
				printf("\n\t\tpress any key  to continue...");
				getch();
				free(hash);
				return 1;
			}
	}
	miscel(a,match);
	printf("\n\t\t MATCH DRAWN");
	free(hash);
	return 0;
	}
bool asknt()
{
	clear;setdisp;
	char c;
	fflush(stdin);
	printf("to stop press(n/N):");
	scanf("%c",&c);
	printf("press any key to continue...");getch();
	return c=='n' || c=='N' ? true : false;
 }
	
void report(player* a)
{
	setdisp;
	printf("name of player:%s\n",a->name);
	setdisp;printf("character:%c\n",a->c);
	setdisp;printf("matches won:%d",a->win);
	getch();
	getchar();
}
void stat(player* a,player *b,char c,int match)
{

	setdisp;hypen;hypen;hypen;
	setdisp;
	match--;
	if(c=='c')
	{
	  printf("match drawn \n\t\t %d matches played",match);
	  //printf("\n\t%s %=%.2f   %s %=%.2f",(float)((a->win/match)*100),(float)((b->win/match)*100));
		printf("\n\t\t%s=%d\t %s=%d",a->name,a->win,b->name,b->win);
	}
	else if(c=='a')
	{
	printf("%s won match \n\t\t%d matches played",a->name,match);
	  //printf("\n\t%s %=%.2f   %s %=%.2f",(float)((a->win/match)*100),(float)((b->win/match)*100));
	printf("\n\t\t%s=%d\t %s=%d",a->name,a->win,b->name,b->win);getch();
	}
		else
	{
	printf("%s won match \n\t\t%d matches played",b->name,match);
	  //printf("\n\t%s %=%.2f   %s %=%.2f",(float)((b->win/match)*100),(float)((a->win/match)*100));
	printf("\n\t\t%s=%d\t %s=%d",a->name,a->win,b->name,b->win);getch();
	}
  }
int _tmain(int argc, _TCHAR* argv[])
{
	int match=1;
	char **mat=(char**)malloc(sizeof(char*)*3);
	for(int  i=0;i<3;i++)
		mat[i]=(char*)malloc(sizeof(char)*3);
	init(mat);
	player *a,*b;
	
	a=getdetails();
	b=getdetails();
	if(a->c==b->c)
	{
		setdisp;printf("both of them selected same characters");getch();return 0;
	}
	while(!asknt())
	{
		init(mat);
	nextmatch(mat,a,b,match);
	match+=1;
	}
	clear;
	report(a);
	report(b);
	//if(match==0)
	//{ setdisp;printf("matches not yet played");
	//}
	//else
	{
	if(a->win==b->win)
		stat(a,b,'c',match);
	else
		a->win>b->win? stat(a,b,'a',match):stat(a,b,'b',match);
	}
	return 0;
system("pause");
getch();
}

