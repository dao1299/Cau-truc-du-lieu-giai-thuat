#include <stdio.h>
#include <stdlib.h>


/* Problem:
 nhap vao stack n so nguyen. in ra stack */

typedef struct {
	int data[100];
	int top;
}stack;

void createStack(stack &s) // Tao stack
{
	s.top=0;
}

int emptyStack(stack s)  // Kiem tra rong Stack
{
	return s.top==0;
}

int overFlowStack(stack s)  //Kiem tra stack day
{
	return s.top==100;
}

void pushStack(stack &s,int x) //Them phan tu x vao stack s
{
	if (overFlowStack(s)==0) 
	{
		s.top++; 
		s.data[s.top]=x;
	}
	else {
		printf("OVER FLOW");
		exit;
	}
}

void popStack(stack &s)
{
	s.top--;
}

int bottomData(stack s)
{
	return s.data[s.top];
}

void printStack(stack s)
{
	printf("\n");
	while (emptyStack(s)!=1)
	{
		printf("%d ",bottomData(s));
		popStack(s);
	}
}

main()
{
	stack s;
	createStack(s);
	int n,i,x;
	printf("N= ");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("nhap gia tri= ");
		scanf("%d",&x);
		pushStack(s,x);
	}
	printStack(s);
}
