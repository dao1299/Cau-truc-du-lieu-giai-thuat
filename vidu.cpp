#include <stdio.h>
#include <conio.h>
main()
{
	int p,q,r;
	printf("p= ");
	scanf("%d",&p);
	printf("q= ");
	scanf("%d",&q);
	r=p%q;
	while (r!=0)
	{
		p=q;
		q=r;
		r=p%q;
	}
	printf("kq= %d ",q);
}
