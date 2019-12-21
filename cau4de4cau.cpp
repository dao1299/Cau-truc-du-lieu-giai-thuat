#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void input(int &n,int a[])
{
	printf("N= ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}

void print(int n,int a[])
{
	printf("\n");
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}

void quickSort(int l,int r,int a[])
{
	int i,j,tg,x;
	i=l;
	j=r;
	x=a[(i+j)/2];
	while (i<j)
	{
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if (i<=j)
		{
			tg=a[i];
			a[i]=a[j];
			a[j]=tg;
			i++;
			j--;	
		} 
	}
	if (l<j) quickSort(l,j,a);
	if (i<r) quickSort(i,r,a);
}
main()
{
	int n,a[100];
	input(n,a);
	print(n,a);
	quickSort(1,n,a);
	print(n,a);
}
