#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct node {
	int mtb;                                               
	int value;
	int sl;
	struct node *next;
};

typedef struct node *ln;

void ListInit(ln &l)
{
	l=NULL;
}

int emp(ln list)
{
	if (list==NULL) return 1;
	else return 0;
}

ln insert_end(ln &l,int a,int b,int c)
{
	ln temp,pre;
	temp= (ln) malloc(sizeof(ln));
	temp->mtb=a;
	temp->value=b;
	temp->sl=c;
	temp->next=NULL;
	if (l==NULL)
		l=temp;
	else
	{
		pre=l;
		while (pre->next!=NULL)
			pre=pre->next;
		pre->next=temp;
	}
}	

ln insert_home(ln &l,int a,int b, int c)
{
	ln temp;
	temp =(ln) malloc (sizeof(ln));
	temp->mtb=a;
	temp->value=b;
	temp->sl=c;
	temp->next=l;
	l=temp;
	return l;
}
void print(ln l)
{
	int count=1;
	printf("\t\t MTB\t SL\t  DG\n");
	while (emp(l)!=1)
	{
		printf("san pham thu %d: %d\t%d\t%d\n",count,l->mtb,l->sl,l->value);
		count++;
		l=l->next;
	}
}
void del_end(ln &l)
{
	ln pre,p;
	p=l;pre=p;
	while (emp(p->next)!=1)
	{
		pre=p;
		p=p->next;
	 } 
	pre->next=NULL;
}
void max(ln l)
{
	ln p;
	p=l;
	int max;
	max=p->value;
	while (p!=NULL)
	{
		if (max<p->value) max=p->value;
		p=p->next;
	}
	printf("san pham co don gia lon nhat:\n");
	printf("\t\t MTB\t SL\t  DG\n");
	while (l!=NULL)
	{
		if (max==l->value) printf("san pham : \t%d\t%d\t%d\n",l->mtb,l->sl,l->value);
		l=l->next;
	}
}
main()
{
	int n,i;
	ln l;
	int a,b,c;
	printf("N= ");
	scanf("%d",&n);
	ListInit(l);
	for (i=1;i<=n;i++)
	{
		printf("nhap ma san phan thu %d: ",i);
		scanf("%d",&a);
		printf("nhap don gia cua san phan thu %d: ",i);
		scanf("%d",&b);
		printf("nhap so luong da mua cua san phan thu %d: ",i);
		scanf("%d",&c);
		insert_end(l,a,b,c);
	}
	printf("\n");
	printf("nhap ma san phan : ");
	scanf("%d",&a);
	printf("nhap don gia cua san pham: ");
	scanf("%d",&b);
	printf("nhap so luong da mua cua san phan: ");
	scanf("%d",&c);
	insert_home(l,a,b,c);
	print(l);
	del_end(l);
	print(l);
	max(l);
}
