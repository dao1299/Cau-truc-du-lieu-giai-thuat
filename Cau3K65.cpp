#include <stdio.h>
#include <conio.h>
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

void insert_tree(tree &t,int &n)
{
	tree p;
	int x;
	int pick;
	if (n==0) exit;
	else
	{
		printf("gia tri nut = ");
		scanf("%d",&x);
		if (t==NULL) 
		{
			p = (tree) calloc (1,sizeof(tree))	;
			p->data=x;
			p->l=NULL;
			p->r=NULL;
			t=p;
			n--;
		}
		if (n>0)
		{	
		printf("Ban co muon nhap cay con trai cho nut %d khong {1/0}",t->data);
		scanf("%d",&pick);
		if (pick==1) insert_tree(t->l,n);
		if (n>0)
		{
			printf("Ban co muon nhap cay con phai cho nut %d khong {1/0}",t->data);
			scanf("%d",&pick);
			if (pick==1) insert_tree(t->r,n);
		}
		else exit;
		}
		else exit;
	}
}

void print_tree(tree t){
	if (t!=NULL)
	{
		
		printf("%d ",t->data);
		print_tree(t->l);
		print_tree(t->r);
	}
}
main(){
	tree t;
	int n,m;
	create_tree(t);
	input(n);
	m=n;
	insert_tree(t,m);
	if (t!=NULL) print_tree(t);
	else printf("NULL");
}
