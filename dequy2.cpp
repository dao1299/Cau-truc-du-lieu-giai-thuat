#include <stdio.h>

float tong(int n)
{
	if (n==2) return 1/float(n);
	else return tong(n-1)+(1/float(n));
}

main()
{
	int n;
	printf("n= ");
	scanf("%d",&n);
	printf("%f",tong(n));
}
