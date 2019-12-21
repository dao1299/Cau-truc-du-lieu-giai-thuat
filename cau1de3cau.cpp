#include <stdio.h>
#include <math.h>
void input(int &p,int &q)
{
	printf("p= ");
	scanf("%d",&p);
	printf("q= ");
	scanf("%d",&q);
}

int khongdequy(int p,int q)
{
	int r=p%q;
	while (r!=0)
	{
		p=q;
		q=r;
		r=p%q;
	}
	return q;	
}
int ucln(int p,int q)
{
	int r;
	r=p%q;
	if (r==0) return q;
	else ucln(q,r);
}
main()
{
	int p,q;
	input(p,q);
	//printf("%d",khongdequy(p,q));
	printf("\n%d",ucln(p,q));
}
