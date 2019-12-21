#include <stdio.h>
#include <conio.h>
main()
{
	int a[100];
	int n,i;
	printf("N= ");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("nhap a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	printf("\n");
	for (i=1;i<=n;i++)
	printf("%d ",a[i]);
}
