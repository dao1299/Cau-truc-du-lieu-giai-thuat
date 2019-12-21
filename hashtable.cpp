#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef node pt;
pt *a[7];
void create()
{
	for (int i=0;i<=7;i++)
	{
		a[i]=NULL;
	}
}
bool search(int x)
{
	pt *p;
	int vt=x%7;
	if (a[vt]==NULL) {
		return false;
	}
	else 
	{
		p=a[vt];
		while (p!=NULL)
		{
			if (p->data==x) return true;
			else p=p->next;
		}
	}
}
void insert(int x)
{
	pt *p;
	if (search(x)==false)
	{
		if (a[x%7]==NULL) 	
		{
			p=(pt *) malloc(sizeof(pt));
			p->data=x;
			p->next=NULL;
			a[x%7]=p;
		}
		else 
		{
			p = (pt*) calloc(1,sizeof(pt));
			p->data=x;
			p->next=a[x%7];
			a[x%7]=p;
		}
	}
}
void print()
{
	pt *p;
	for (int i=0;i<7;i++)
	{
		p=a[i];
		printf("du %d: ",i);
		while (p!=NULL)
		{
			printf("%d-",p->data);
			p=p->next;
		}
		printf("NULL\n");
	}
}
main()
{
	int i,x,c;
	create();
	do
	{
		printf("\n1. Chen");
		printf("\n2. Tim");
		printf("\n3. In");
		printf("\n4. Exit");
		printf("\nplease choose: ");
		scanf("%d",&c);
		switch (c)
		{
			case 1: printf("x= ");
					scanf("%d",&x);
					insert(x);
					printf("\ndone!");
					break;
			case 2: printf("\nnhap so can tim=" );
					scanf("%d",&x);
					if (search(x)==true) printf("Tim thay ne (^ ^)");
						else printf("Suyt thi tim duoc (T T)");
					break;
			case 3: print();
					break;
		}
	}
	while (c!=4);
}
