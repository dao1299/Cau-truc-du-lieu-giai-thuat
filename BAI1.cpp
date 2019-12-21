#include <stdio.h>

int tong(int n)
{
	if (n==0) return 0;
	else return tong(n-1)+n; 
}
main()
{
	int n;
	printf("n= ");
	scanf("%d",&n);
	printf("%d",tong(n));
}
