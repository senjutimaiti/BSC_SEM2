#include<stdio.h>
#define MAX 5
/*
void push(int s[],int *top,int value)
{
	if(*top==0)
	{
		if(s[*top+1]==NULL)
			s[++*top]=value;
		else
			printf("Stack overflow");
	}
	else
	{
		s[++*top]=value;
		if(*top+1==MAX)
			*top=0;
	}
}
void pop(int s[],int *top)
{
	if(*top==0)
	{
		if(s[*top+1]==NULL)
			printf("Stack underflow\n");
		else
			*top=MAX-1;
	}
	if(*top>0)
	{
		printf("The value popped: %d", s[*top]);
		s[*top]=NULL;
		*top=*top-1;
	}
}
void display(int s[],int *top)
{
	int i=0,t;
	printf("The current Stack\n");
	if(*top==0 && s[*top+1]==NULL)
	{
		printf("Stack underflow\n");
	}
	else
	{
		if(*top==0)
			t=MAX-1;
		else
			t=*top;
		for(i=1;i<=t;i++)
		{
			printf("%d\t",s[i]);
		}	
	}	
}
*/
void push(int s[],int *top,int value,int *e)
{
	if(*e!=0 && ((*top+1)%MAX)!=0)
	{
		*top=(*top+1)%MAX;
		s[*top]=value;
	}
	else
	{
		*e=0;
		printf("Stack overflow");
	}
}
void pop(int s[],int *top,int *e)
{
	if(*e==1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("The value popped: %d", s[*top]);
		if(--*top==0)
			*e=1;
	}
}
void display(int s[],int *top,int *e)
{
	int i=0,t;
	printf("The current Stack\n");
	if(*e==1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		for(i=1;i<=*top;i++)
		{
			printf("%d\t",s[i]);
		}	
	}	
}
void peek(int s[],int *top)
{
	if(*top==0 && s[*top+1]==NULL)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("The value peeked: %d", s[*top]);
	}
}
void main()
{
	int n,value,f,e=1;
	int s[MAX]={NULL};
	int top=0;
	do
	{
		printf("1. push\n2. pop\n3. peek\n4. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				push(s,&top,value,&e);
				break;
			}
			case 2: pop(s,&top,&e);
				break;
			case 3: peek(s,&top);
				break;
			case 4: display(s,&top,&e);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
