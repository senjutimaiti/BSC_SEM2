#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 30
struct stck
{
	int top;
	char a[MAX];
};
typedef struct stck STK;
void push1(STK *p,int value)
{
	p->a[++p->top]=value;
}
int pop1(STK *p)
{
	return p->a[p->top--];
}
int calculate(int a, int b, char c)
{
	if(c=='+')
	{
		return (b+a);
	}
	if(c=='-')
	{
		return (b-a);
	}
	if(c=='*')
	{
		return (b*a);
	}
	if(c=='/')
	{
		return (b/a);
	}
	if(c=='^')
	{
		return pow(b,a);
	}
	if(c=='%')
	{
		return (b%a);
	}
}
void main()
{
	int f=0,key,a,b,res,i;
	char ch,c,p[MAX];
	printf("Enter a postfix expression\n");
	fflush(stdin);
	gets(p);
	STK sk;
	sk.top=-1;
	while(p[f]!='\0')
	{
		ch=*(p+f);
		key=(ch);
		for(i=0;i<=9;i++)
		{
			if(key==(48+i))
			{
				key=i;
				break;
			}
		}
		if(key>=0 && key<=9)
		{
			push1(&sk,key);
		}
		else
		{
			a=pop1(&sk);
			b=pop1(&sk);
			res=calculate(a,b,ch);
			//printf("%d ",res);
			push1(&sk,res);
		}
		f++;
	}
	printf("\nThe result = %d", res);
}
