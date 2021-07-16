#include<stdio.h>
#define MAX 10
void push1(int s[],int *top1,int *top2,int value)
{
	if(*top1+1==*top2)
	{
		printf("Stack overflow");
	}
	else
	{
		s[++*top1]=value;
	}
}
void push2(int s[],int *top1,int *top2,int value)
{
	if(*top1+1==*top2)
	{
		printf("Stack overflow");
	}
	else
	{
		s[--*top2]=value;
	}
}
void pop1(int s[],int *top1,int *top2)
{
	if(*top1==-1)
	{
		printf("Stack1 underflow");
	}
	else
	{
		printf("The value popped: %d", s[*top1]);
		*top1=*top1-1;
	}
}
void pop2(int s[],int *top1,int *top2)
{
	if(*top2==MAX)
	{
		printf("Stack2 underflow");
	}
	else
	{
		printf("The value popped: %d", s[*top2]);
		*top2=*top2+1;
	}
}
void display(int s[],int *top1,int *top2)
{
	int i=0;
	if(*top1==-1 && *top2==MAX)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("The current Stacks\n");
		for(i=0;i<=*top1;i++)
		{
			printf("%d\t",s[i]);
		}
		printf("\n");
		for(i=*top2;i<MAX;i++)
		{
			printf("%d\t",s[i]);
		}	
	}	
}
void main()
{
	int n,value,f;
	int s[MAX];
	int top1=-1,top2=MAX;
	do
	{
		printf("1. push from stack1\n2. pop from stack1\n3. push from stack2\n4. pop from stack2\n5. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				push1(s,&top1,&top2,value);
				break;
			}
			case 2: pop1(s,&top1,&top2);
				break;
			case 3: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				push2(s,&top1,&top2,value);
				break;
			}
			case 4: pop2(s,&top1,&top2);
				break;
			case 5: display(s,&top1,&top2);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
