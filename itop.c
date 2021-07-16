#include<stdio.h>
#define MAX 30
struct STACK
{
	int top;
	char a[MAX];
};
typedef struct STACK ST;
void push(ST *p,char value)
{
	p->a[++p->top]=value;
}
char pop(ST *p)
{
	return p->a[p->top--];
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
void main()
{
	int n=0,key,f=0,pr1,pr2;
	char ch,c;
	ST stack;
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
			push(&stack,ch);
		}
		else if(ch==')'||ch=='}'||ch==']')
		{
			while(stack.top!=-1 && stack.a[stack.top]!='(' && stack.a[stack.top]!='{' && stack.a[stack.top]!='[')
			{
				c=pop(&stack);
				post[n++]=c;
			}
			if(stack.top==-1)
			{
				printf("Incorrect expression");
			}
			c=pop(&stack);
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
						c=pop(&stack);
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
			push(&stack,ch);
		}
		else
		{
			printf("Incorrect element in expression");
		}
		f++;
	}
	while(stack.top!=-1 && (stack.a[stack.top]!='('||stack.a[stack.top]!='{'||stack.a[stack.top]!='['))
	{
		c=pop(&stack);
		post[n++]=c;
	}
	if(stack.a[stack.top]=='('||stack.a[stack.top]=='{'||stack.a[stack.top]=='[')
	{
		printf("Incorrect Expression");
	}
	post[n]='\0';
	printf("The postfix expression\n");
	puts(post);
}
