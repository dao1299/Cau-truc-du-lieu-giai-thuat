#include <stdio.h>
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
void quicksort(int l,int r,int a[])
{
	int i=l,j=r,x=(i+j)/2,tg;
	while (i<j)
	{
		while (a[i]<a[x]) i++;
		while (a[j]>a[x]) j--;
		if (i<=j)
		{
			tg=a[i];
			a[i]=a[j];
			a[j]=tg;
			i++;
			j--;
		}
	}
	if (l<j) quicksort(l,j,a);
	if (i<r) quicksort(i,r,a);
}
void merge(int )
void output(int n,int a[])
{
	for (int i=1;i<=n;i++)
	printf("%d ",a[i]);
}
main()
{
	int a[100],n;
	input(n,a);
	output(n,a);
	printf("\nSau quicksort: ");
	quicksort(1,n,a);
	output(n,a);
}
