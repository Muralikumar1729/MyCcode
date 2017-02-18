#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>
#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include"cstdlib"
int pro=0;

void product(int n1,int n2)
{


	for(int i=1;i<32;i++)
	{
		if(n2&1)
			pro+=n1;
		n2>>=1;
		n1<<=1;

	}
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n1,n2;

	printf("\nEnter Number1 : ");
	scanf("%d",&n1);
	printf("\nEnter Number2 : ");
	scanf("%d",&n2);
	printf("\nNumber1 : ");
	printf("%d\n",n1);
	printf("\nNumber2 : ");
	printf("%d\n",n2);
	product(n1,n2);

	printf("\nProduct : ");
	printf("%d\n",pro);
	system("PAUSE");
	getch();
	return 0;
}




