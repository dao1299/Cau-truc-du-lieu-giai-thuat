#include <stdio.h>

int tcs(int n)
{
	if (n/10==0) return n;
	else return tcs(n/10)+(n%10);
}

main()
{
	int n;
	printf("n= ");
	scanf("%d",&n);
	printf("%d",tcs(n));
}
