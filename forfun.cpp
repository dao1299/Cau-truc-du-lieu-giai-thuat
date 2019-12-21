#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complexNumber{
	int thuc,ao;
};
void input(int &n,complexNumber a[])
{
	printf("N= ");
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++)
	{
		printf("So thu %d: ",i);
		printf("\nPhan thuc = ");
		scanf("%d",&a[i].thuc);
		printf("Phan ao = ");
		scanf("%d",&a[i].ao);
		
	}
}
void print(int n,complexNumber a[])
{
	int i;
	for (i=1;i<=n;i++)
	{
		if (a[i].ao>0) printf("\n%d + %di",a[i].thuc,a[i].ao);
		if (a[i].ao<0) printf("\n%d - %di",a[i].thuc,abs(a[i].ao));
	}	
}

void findMax(int n,complexNumber a[])
{
	int max=a[1].thuc*a[1].thuc+a[1].ao*a[1].ao;
	int i;
	for (i=2;i<=n;i++)
	{
		if (max<(a[i].thuc*a[i].thuc+a[i].ao*a[i].ao))
		{
			max=a[i].thuc*a[i].thuc+a[i].ao*a[i].ao;
		}
	}
	printf("\nSo phuc co modul lon nhat: ");
	for (i=1;i<=n;i++)
	{
		if (max=(a[i].thuc*a[i].thuc+a[i].ao*a[i].ao))
		{
			if (a[i].ao>0) printf("\n%d + %di",a[i].thuc,a[i].ao);
			if (a[i].ao<0) printf("\n%d - %di",a[i].thuc,abs(a[i].ao));
		}
	}
}
main()
{
	complexNumber a[100];
	int n,i;
	input(n,a);
	print(n,a);
	findMax(n,a);
}


