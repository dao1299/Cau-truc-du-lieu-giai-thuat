#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node {
	long ms;
	char ts[10];
	long dg,sl;
	struct node *next;
};

typedef struct node *ln;

void createList(ln &l)
{
	l=NULL;
}

int emptyList(ln l)
{
	return l==NULL;
}

void input(int &n)
{
	printf("N= ");
	scanf("%d",&n);
}

void insertHead(ln &l)
{
	ln temp,p;
	char ten[10];
	long dongia,soluong,masach;
	printf("\nMa sach= ");
	scanf("%d",&masach);
	printf("Ten sach= ");
	fflush(stdin);
	gets(ten);
	printf("Don gia= ");
	scanf("%d",&dongia);
	printf("So luong= ");
	scanf("%d",&soluong);
	temp = (ln) calloc (10,sizeof(ln));
	temp->ms=masach;
	temp->sl=soluong;
	temp->dg=dongia;
	strcpy(temp->ts,ten);
	temp->next=l;
	l=temp;
}

void printList(ln l)
{
	while (emptyList(l)!=1)
	{
		printf("\n%d %s %d %d",l->ms,l->ts,l->dg,l->sl);
		l=l->next;
	}
}
void revenue(ln l)
{
	unsigned long t=0;
	while (emptyList(l)!=1)
	{
		t+=l->dg*l->sl;
		l=l->next;
	}
	printf("\nRevenue = %lld",t);
}
main()
{
	ln l;
	int n,i;
	createList(l);
	input(n);
	for (i=1;i<=n;i++)
	insertHead(l);
	printList(l);
	insertHead(l);
	printList(l);
	revenue(l);
}
