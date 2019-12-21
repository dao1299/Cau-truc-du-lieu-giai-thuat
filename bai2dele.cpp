#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
	int MCB;
	char ten[10];
	int ns;
	int luong;
	struct node *l,*r;
};

typedef struct node * tree;

void createTree(tree &t)
{
	t=NULL;
}

tree createnode(int a,char b[],int c)
{
	tree temp;
	temp = (tree) calloc (100,sizeof(tree));
	temp->MCB=a;
	strcpy(temp->ten,b);
	temp->ns=c;
	temp->luong=(2019 - temp->ns)*300;
	temp->l=temp->r=NULL;
	return temp;
}

void insert(tree &t,tree &p)
{
	if (t==NULL) t=p;
	else {
		if(t->l==NULL)
		{
			insert(t->l,p);
		}
		else insert(t->r,p);
	}
}
void print(tree t)
{
	
	if (t!=NULL)
	{
		printf("%d\t%s\t%d\t\t%d\n",t->MCB,t->ten,t->ns,t->luong);
		print(t->l);
		print(t->r);
	}
}
int chieucao(tree t)
{
	int a=0,b=0;
	if (t!=NULL)
	{
		a=chieucao(t->l);
		b=chieucao(t->r);
		if  (a>b) return a+1;
	else return b+1;
	}
}
void search(tree t,int &tt)
{
	char temp[5] = "thuy";
	if (t!=NULL)
	{
		if (strcmp(t->ten,temp)==0 ) 
		{
			printf("%d\t%s\t%d\t\t%d\n",t->MCB,t->ten,t->ns,t->luong);
			tt++;
		}
		search(t->l,tt);
		search(t->r,tt);
	}
}
int main()
{
	int n,i,a,c,tt=0;
	char b[10];
	tree t,p;
	createTree(t);
	printf("N= ");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("Ma CB thu %d: ",i);
		scanf("%d",&a);
		printf("Ten nguoi thu %d: ",i);
		fflush(stdin);
		gets(b);
		printf("Nam sinh cua nguoi thu %d: ",i);
		scanf("%d",&c);
		p=createnode(a,b,c);
		//printf("qua");
		insert(t,p);
	}
	printf("MCB\tTen\tNam Sinh\tLuong\n");
	print(t);
	printf("\nChieu cao cua cay la: %d",chieucao(t));
	printf("\nDanh sach can bo ten 'Thuy' va co luong >=2000:\n");
	printf("MCB\tTen\tNam Sinh\tLuong\n");
	search(t,tt);
	if (tt==0) printf("\nKHONG CO AI");
	//free(p);
	return 0;
}
