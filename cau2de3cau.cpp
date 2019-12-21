#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	int top;
	float mu[100],heso[100];
}stack;

void createStack(stack &s)
{
	s.top=0;
}

int  checkEmpty(stack s)
{
	return s.top==0;
}

void push(stack &s,float x,float y)
{
	s.top++;
	s.mu[s.top]=y;
	s.heso[s.top]=x;
}

void printStack(stack s)
{
	while (checkEmpty(s)!=1)
	{
		printf("%.2f x ^ %.2f \n",s.heso[s.top],s.mu[s.top]);
		s.top--;
	}
}

void printValues(stack s,float x)
{
	float t=0;
	while (checkEmpty(s)!=1)
	{
		t+=s.heso[s.top]*(pow(x,s.mu[s.top]));
		s.top--;
	}
	printf("Values = %.5f",t);
}

main()
{
	stack s;
	createStack(s);
	float x,y;
	int n,i;
	printf("N= ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		printf("He so= ");
		scanf("%f",&x);
		printf("So mu= ");
		scanf("%f",&y);
		push(s,x,y);
	}	
	printStack(s);
	printf("\nX= ");
	scanf("%f",&x);
	printValues(s,x);
}
