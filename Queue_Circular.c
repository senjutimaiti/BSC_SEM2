#include<stdlib.h>
#include<stdio.h>
#define MAX 5
void cqInsert(int q[],int *front,int *rear,int value)
{
	if((*rear+1)%MAX==*front)
	{
		printf("Queue overflow");
	}
	else
	{
		if(*front==-1)
		{
			*front=0;
			*rear=0;
		}
		else
			*rear=(*rear+1)%MAX;	
		q[*rear]=value;
	}
}
void cqDelete(int q[],int *front,int *rear)
{
	if(*front==-1)
	{
		printf("Queue underflow");
	}
	else
	{
		printf("The value popped: %d", q[*front]);
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
			*front=(*front+1)%MAX;
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
		i=*front;
		while(i!=*rear)
		{
			printf("%d ",q[i]);
			i=(i+1)%MAX;
		}
		printf("%d ",q[i]);
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
		printf("1. Insert\n2. Delete\n3. Display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				cqInsert(q,&front,&rear,value);
				break;
			}
			case 2: cqDelete(q,&front,&rear);
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
