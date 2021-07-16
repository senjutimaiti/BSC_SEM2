#include<stdio.h>
#define MAX 5
void push(int s[],int *top,int value)
{
	if(*top==MAX-1)
	{
		printf("Stack overflow");
	}
	else
	{
		s[++*top]=value;
	}
}
void pop(int s[],int *top)
{
	if(*top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("The value popped: %d", s[*top]);
		*top=*top-1;
	}
}
void peek(int s[],int *top)
{
	if(*top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("The value peeked: %d", s[*top]);
	}
}
void display(int s[],int *top)
{
	int i=0;
	printf("The current Stack\n");
	if(*top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		for(i=0;i<=*top;i++)
		{
			printf("%d\t",s[i]);
		}	
	}	
}
void main()
{
	int n,value,f;
	int s[MAX];
	int top=-1;
	do
	{
		printf("1. push\n2. pop\n3. peek\n4. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				push(s,&top,value);
				break;
			}
			case 2: pop(s,&top);
				break;
			case 3: peek(s,&top);
				break;
			case 4: display(s,&top);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
