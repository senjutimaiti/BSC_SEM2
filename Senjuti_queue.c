#include<stdlib.h>
#include<stdio.h>
#define MAX 5
struct queue
{
	int front;
	int rear;
	int a[MAX];
};
typedef struct queue Q;
void enqueue(Q *p,int value)
{
	if(p->rear==MAX-1)
	{
		if(p->front==0)
			printf("Queue overflow");
		else
		{
			int i;
			for(i=p->front;i<=p->rear;i++)
				p->a[i-p->front]=p->a[i];
			p->rear=p->rear-p->front;
			p->front=0;
			p->a[++p->rear]=value;
		}
	}
	else
	{
		if(p->front==-1)
			p->front=0;
		p->a[++p->rear]=value;
	}
}
void dequeue(Q *p)
{
	if(p->front==-1)
	{
		printf("Queue underflow");
	}
	else
	{
		printf("The value deleted: %d", p->a[p->front]);
		if(p->front==p->rear)
		{
			p->front=-1;
			p->rear=-1;
		}
		else
		p->front++;
	}
}
void display(Q *p)
{
	int i=0;
	if(p->front==-1)
	{
		printf("Queue empty");
	}
	else
	{
		printf("The current Queue\n");
		for(i=p->front;i<=p->rear;i++)
		{
			printf("%d\t",p->a[i]);
		}	
	}	
}
void main()
{
	int n,value,f;
	Q queue;
	queue.front=-1;
	queue.rear=-1;
	do
	{
		printf("1. enqueue\n2. dequeue\n3. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be inserted: ");
				scanf("%d", &value);
				enqueue(&queue,value);
				break;
			}
			case 2: dequeue(&queue);
				break;
			case 3: display(&queue);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
