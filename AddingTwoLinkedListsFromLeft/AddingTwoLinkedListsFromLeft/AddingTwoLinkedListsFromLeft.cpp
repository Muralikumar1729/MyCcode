// AddingTwoLinkedListsFromLeft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// addingfromleft.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "malloc.h"
#include "cstdlib"

struct node* creatinglinkedlist(char[], int);

struct node
{
	int d;
	struct node *p;
}*head, *mai, *temp2, *temp3;
struct node * sum(struct node *h1, struct node *h2)
{
	mai = '\0';
	int carry = 0, reminder, t1, t2;

	if (h1 && h2)
	{
		if (mai == '\0')
		{
			mai = (struct node *) malloc(sizeof(struct node));
			reminder = h1->d + h2->d + carry;
			if (reminder>9)
			{
				t1 = reminder % 10;
				t2 = reminder / 10;
				reminder = t1;
				carry = t2;
			}
			mai->d = reminder;
			mai->p = '\0';
			temp3 = mai;
		}
		h1 = h1->p;
		h2 = h2->p;
	}
	while (h1 && h2)
	{
		temp2 = (struct node *) malloc(sizeof(struct node));
		reminder = h1->d + h2->d + carry;
		carry = 0;
		if (reminder>9)
		{
			t1 = reminder % 10;
			t2 = reminder / 10;
			reminder = t1;
			carry = t2;
		}
		temp2->d = reminder;
		temp2->p = '\0';
		temp3->p = temp2;
		temp3 = temp2;
		h1 = h1->p;
		h2 = h2->p;
	}
	if (h1 == '\0' && h2 != '\0')
	{
		while (h2)
		{
			temp2 = (struct node *) malloc(sizeof(struct node));
			reminder = h2->d + carry;
			carry = 0;
			if (reminder>9)
			{
				t1 = reminder % 10;
				t2 = reminder / 10;
				reminder = t1;
				carry = t2;
			}
			temp2->d = reminder;
			temp2->p = '\0';
			temp3->p = temp2;
			temp3 = temp2;
			h2 = h2->p;
		}
	}
	if (h1 != '\0' && h2 == '\0')
	{
		while (h1)
		{
			temp2 = (struct node *) malloc(sizeof(struct node));
			reminder = h1->d + carry;
			carry = 0;
			if (reminder>9)
			{
				t1 = reminder % 10;
				t2 = reminder / 10;
				reminder = t1;
				carry = t2;
			}
			temp2->d = reminder;
			temp2->p = '\0';
			temp3->p = temp2;
			temp3 = temp2;
			h1 = h1->p;
		}
	}
	if (carry != 0)
	{
		temp2 = (struct node *) malloc(sizeof(struct node));
		temp2->d = carry;
		temp2->p = '\0';
		temp3->p = temp2;
		temp3 = temp2;
	}
	return mai;

}
struct node* creatinglinkedlist(char s[], int i)
{
	struct node *temp;
	int count = 0;
	head = '\0';

	for (; s[i] != '\0'; i++)
	{
		temp = (struct node *) malloc(sizeof(struct node));
		temp->d = s[i] - '0';
		temp->p = head;
		head = temp;
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	struct node *h1, *h2, *h3, *a;
	char s1[100], s2[100];
	printf("enter first string");
	scanf("%s", &s1);
	printf("enter second string");
	scanf("%s", &s2);
	for (i = 0; s1[i] == '0'; i++);

	h1 = creatinglinkedlist(s1, i);

	for (i = 0; s2[i] == '0'; i++);

	h2 = creatinglinkedlist(s2, i);
	a = h1;
	while (a)
	{
		printf("%d", a->d);
		a = a->p;
	}

	h3 = sum(h1, h2);
	while (h3)
	{
		printf("-%d\n", h3->d);
		h3 = h3->p;

	}
	//getch();
	return 0;
}






