#include<stdlib.h>
#include<stdio.h>
#define MAX 5
void InsertFront(int q[],int *front,int *rear,int value)
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
		else if(*front==0)
			*front=MAX-1;
		else
			*front=*front-1;	
		q[*front]=value;
	}
}
void InsertRear(int q[],int *front,int *rear,int value)
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
void DeleteFront(int q[],int *front,int *rear)
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
void DeleteRear(int q[],int *front,int *rear)
{
	if(*front==-1)
	{
		printf("Queue underflow");
	}
	else
	{
		printf("The value popped: %d", q[*rear]);
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else if(*rear==0)
			*rear=MAX-1;
		else
			*rear=*rear-1;
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
		if(*front<=*rear)
		{
			for(i=*front;i<=*rear;i++)
			{
				printf("%d\t",*(q+i));
			}
		}
		else
		{
			for(i=*front;i<MAX;i++)
			{
				printf("%d\t",*(q+i));
			}	
			for(i=0;i<=*rear;i++)
			{
				printf("%d\t",*(q+i));
			}
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
		printf("1. Insert from front\n2. Delete from front\n3. Insert from rear\n4. Delete from rear\n5. Display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				InsertFront(q,&front,&rear,value);
				break;
			}
			case 2: DeleteFront(q,&front,&rear);
				break;
			case 3: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				InsertRear(q,&front,&rear,value);
				break;
			}
			case 4: DeleteRear(q,&front,&rear);
				break;
			case 5: display(q,&front,&rear);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
