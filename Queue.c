#include<stdlib.h>
#include<stdio.h>
#define MAX 5
void enqueue(int q[],int *front,int *rear,int value)
{
	if(*rear==MAX-1)
	{
		printf("Queue overflow");
	}
	else
	{
		if(*front==-1)
			*front=0;
		q[++*rear]=value;
	}
}
void dequeue(int q[],int *front,int *rear)
{
	if(*front==-1)
	{
		printf("Queue underflow");
	}
	else
	{
		printf("The value deleted: %d", q[*front]);
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
			*front=*front+1;
	}
}
void display(int q[],int *front,int *rear)
{
	int i=0;
	if(*front==-1)
	{
		printf("Queue empty");
	}
	else
	{
		printf("The current Queue\n");
		for(i=*front;i<=*rear;i++)
		{
			printf("%d\t",*(q+i));
		}	
	}	
}
void main()
{
	int n,value,f;
	int q[MAX];
	int front=-1;
	int rear=-1;
	do
	{
		printf("1. enqueue\n2. dequeue\n3. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				enqueue(q,&front,&rear,value);
				break;
			}
			case 2: dequeue(q,&front,&rear);
				break;
			case 3: display(q,&front,&rear);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
