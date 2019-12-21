#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *l,*r;
};
typedef struct node *tree;
void create_tree(tree &t)
{
	t=NULL;	
}
void input(int &n)
{
	printf("n= ");
	scanf("%d",&n);
}
void insert_tree(tree &t,int x)
{
	tree temp;
	if (t==NULL) 
	{
		temp= (tree) calloc (1,sizeof(tree));
		temp->data=x;
		temp->l=NULL;
		temp->r=NULL;
		t=temp;
	}
	else 
	{
		if (x==t->data) exit;
			else 
			{
				if (x>t->data) insert_tree(t->r,x);
				else insert_tree(t->l,x);
			}
	}
}
void print_tree(tree t){
	if (t!=NULL)
	{
		print_tree(t->l);
		printf("%d ",t->data);
		print_tree(t->r);
	}
}
main(){
	tree t;
	int n,i,x;
	create_tree(t);
	input(n);
	for (i=1;i<=n;i++)
	{
		printf("value = ");
		scanf("%d",&x);
		insert_tree(t,x);
	}
	printf("\n");
	print_tree(t);
}
