#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(int &n)
{
	printf("N= ");
	scanf("%d",&n);
}

void solution(long day[],int n)
{
	day[1]=1;
	day[2]=3;
	int i;
	for (i=3;i<=n;i++)
	day[i]=(day[i-1]*day[i-1]) + (3*day[i-2]);
	printf("\nkq1= %lld",day[n]);
}

long a(long n)
{
	if (n==1) return 1;
	if (n==2) return 3;
	return a(n-1)*a(n-1)+3*a(n-2); 
}
main()
{
	long day[100];
	int n;
	input(n);
	solution(day,n);
	printf("\nkq2 = %lld ",a(n));
}
