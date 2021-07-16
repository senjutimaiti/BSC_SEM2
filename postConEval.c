#include<stdio.h>
#include <math.h>
#define MAX 30
struct STACK
{
	int top;
	char a[MAX];
};
typedef struct STACK STK;
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
void postfix_evaluation(char* p)
{
	int f=0,key,a,b,res,i;
	char ch,c;
	STK sk;
	sk.top=-1;
	while(*(p+f)!='\0')
	{
		ch=*(p+f);
		key=ch;
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
			sk.a[++sk.top]=key;
		}
		else
		{
			a=sk.a[sk.top--];
			b=sk.a[sk.top--];
			res=calculate(a,b,ch);
			sk.a[++sk.top]=res;
		}
		f++;
	}
	printf("The result = %d", res);
}
int precedence(char ch)
{
	if(ch=='^')
	{
		return 3;
	}
	if(ch=='*'||ch=='/'||ch=='%')
	{
		return 2;
	}
	if(ch=='+'||ch=='-')
	{
		return 1;
	}
}
void postfix()
{
	int n=0,key,f=0,pr1,pr2,res;
	char ch,c;
	STK stack;
	stack.top=-1;
	char in[MAX],post[MAX];
	printf("Enter an infix expression\n");
	fflush(stdin);
	gets(in);
	while(*(in+f)!='\0')
	{
		ch=*(in+f);
		key=ch;
		if(ch=='('||ch=='{'||ch=='[')
		{
			stack.a[++stack.top]=ch;
		}
		else if(ch==')'||ch=='}'||ch==']')
		{
			while(stack.top!=-1 && stack.a[stack.top]!='(' && stack.a[stack.top]!='{' && stack.a[stack.top]!='[')
			{
				c=stack.a[stack.top--];
				post[n++]=c;
			}
			if(stack.top==-1)
			{
				printf("Incorrect expression");
			}
			c=stack.a[stack.top--];
		}
		else if((key>=65 && key<=90)||(key>=97 && key<=122)||(key>=48 && key<=57))
		{
			post[n++]=ch;
		}
		else if(ch=='^'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
		{
			while(stack.top!=-1)
			{
				if(stack.a[stack.top]=='^'||stack.a[stack.top]=='*'||stack.a[stack.top]=='/'||stack.a[stack.top]=='%'||stack.a[stack.top]=='+'||stack.a[stack.top]=='-')
				{
					pr1=precedence(stack.a[stack.top]);
					pr2=precedence(ch);
					if(pr1>=pr2)
					{
						c=stack.a[stack.top--];
						post[n++]=c;
					}
					else
					break;
				}
				else
				{
					break;
				}
			}
			stack.a[++stack.top]=ch;
		}
		else
		{
			printf("Incorrect element in expression");
		}
		f++;
	}
	while(stack.top!=-1 && (stack.a[stack.top]!='('||stack.a[stack.top]!='{'||stack.a[stack.top]!='['))
	{
		c=stack.a[stack.top--];
		post[n++]=c;
	}
	if(stack.a[stack.top]=='('||stack.a[stack.top]=='{'||stack.a[stack.top]=='[')
	{
		printf("Incorrect Expression");
	}
	post[n]='\0';
	printf("The postfix expression\n");
	puts(post);
	postfix_evaluation(post);
}
void main()
{
	postfix();
}
