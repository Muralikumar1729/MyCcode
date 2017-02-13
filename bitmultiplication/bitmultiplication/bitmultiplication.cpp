// bitmultiplication.cpp : Defines the entry point for the console application.
//

// mul 160 bit  and 90 bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<conio.h>
void leftshift(unsigned int *n,unsigned int l)
{
	int i;
	int c=0,c1;
	for(i=0;i<l;i++)
	{
		c1=n[i]>>31;
		n[i]=n[i]<<1;
		n[i]=n[i]|c;
		c=c1;
	}
}
void add(unsigned int * n1,unsigned int * r,unsigned int l1)
{
	int i;
	unsigned long long l;
	for(i=0;i<l1;i++)
	{
		l=n1[i]+r[i];
		r[i]=l&0x00000000ffffffff;
		r[i+1]=l>>32;
	}
}
void mul(unsigned int * n1,unsigned int * n2,unsigned int l1,unsigned int l2,unsigned int * r)
{
	int i,j;
	for(i=0;i<l1+l2;i++)
	{
		r[i]=0;
	}
	for(i=l2-1;i>=0;i--)
	{
		for(j=31;j>=0;j--)
		{
			leftshift(r,l1+l2);
			if(n2[i]&(1<<j))
			{
			add(n1,r,l1);
			}
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	unsigned int l1,l2;
	unsigned int *n1,*n2,*r;
	scanf("%u",&l1);
	n1=(unsigned int *)malloc(sizeof(unsigned int)*l1);
	for(i=l1-1;i>=0;i--)
	{
		scanf("%u",&n1[i]);
	}
	scanf("%u",&l2);
	n2=(unsigned int *)malloc(sizeof(unsigned int)*l2);
	for(i=l2-1;i>=0;i--)
	{
		scanf("%u",&n2[i]);
	}
	r=(unsigned int *)malloc(sizeof(unsigned int)*(l1+l2));
	mul(n1,n2,l1,l2,r);
	for(i=l1+l2-1;i>=0;i--)
	{
		printf("%u",r[i]);
	}
	getch();
	return 0;
}

