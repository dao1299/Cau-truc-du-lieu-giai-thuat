#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *l,*r;
};
typedef struct node *tree;

void createTree(tree &t)
{
	t=NULL;
}

void push(tree &t,int x)
{
	tree p,temp;
	if (t==NULL)
	{
		p = (tree) calloc (1,sizeof(tree));
		p->data=x;
		p->l=NULL;
		p->r=NULL;	
		t=p;
	}
	else 
	{
		if (x>t->data) push(t->r,x);
		if (x<t->data) push(t->l,x);
	}
}

void printTree(tree t)
{
	if (t!=NULL)
	{
		printTree(t->l);
		printf("%d ",t->data);
		printTree(t->r);
	}
}

void search(tree t,int k)
{
	if (t==NULL) printf("\nKhong tim thay");
	else {
		if (t->data == k) printf("\nTim thay");
		if (t->data>k) search(t->l,k);
		if (t->data<k) search(t->r,k);
	}
}
main()
{
	int n,k,x;
	tree t,p;
	createTree(t);
	printf("N= ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		printf("value = ");
		scanf("%d",&x);
		push(t,x);
	}
	
	printf("K= ");
	scanf("%d",&k);
	printTree(t);
	search(t,k);
}
