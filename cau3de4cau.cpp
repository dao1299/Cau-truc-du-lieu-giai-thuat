#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node{
	char data[10];
	struct node *l,*r;
};

typedef struct node *tree;

void createTree(tree &t)
{
	t=NULL;
}

int kiemtra(char s[10])
{
	int i;
	for (i=0;i<strlen(s);i++)
	if ((s[i]=='c') or (s[i]=='C')) return 1;
	return 0;
}

void insertTree(tree &t,int &tt,int &count)
{
	char s[10];
	tree p;
	int c;
	if (tt==0) exit;
	else
	{
		if (t==NULL)
		{
			p = (tree) calloc (5,sizeof(tree));
			printf("Values: ");
			fflush(stdin);
			gets(s);
			if (kiemtra(s)==1) 
			{
				strcpy(p->data,s);
				p->l=NULL;
				p->r=NULL;
				t=p;
				count++;
			}	
			else 
			{
				tt=0;
				exit;
			}
			
		}
		if (tt==1)
		{
			printf(" left %s ? :",t->data);
			scanf("%d",&c);
			if (c==1) insertTree(t->l,tt,count);
			else t->l=NULL;
			if (tt==1)
			{
				printf(" right %s ? :",t->data);
				scanf("%d",&c);
				if (c==1) insertTree(t->r,tt,count);
				else t->r=NULL;
			}
			else 
			{
				tt=0;
				exit;
			}
		}	
			else 
			{
				tt=0;
				exit;
			}
	}
}


int highTree(tree t)
{
	int a,b;
	if (t!=NULL)
	{
		a=highTree(t->l);
		b=highTree(t->r);
		if (a>b) return a+1;
		else return b+1;
	}
}
void printTree(tree t)
{
	if (t!=NULL)
	{
		printf("%s ",t->data);
		printTree(t->l);
		printTree(t->r);
	}
}

main()
{
	tree t;
	int tt=1,count=0;
	createTree(t);
	char s[10];
	insertTree(t,tt,count);
	printTree(t);
	printf("\nchieu cao cua cay = %d %d",highTree(t),count);
}
