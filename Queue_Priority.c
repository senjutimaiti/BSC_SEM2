#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 5
void pqInsert(int q[MAX][MAX],int front[],int rear[],int val,int pval)
{
	int i=pval-1;
	if((rear[i]+1)%MAX==front[i])
	{
		printf("Queue Overflow");
	}
	else
	{
		if(front[i]==-1)
		{
			front[i]=0;
			rear[i]=0;
		}
		else
			rear[i]=(rear[i]+1)%MAX;	
		q[i][rear[i]]=val;
	}
}
void pqDelete(int q[MAX][MAX],int front[],int rear[])
{
	int f=0,i=0;
	while(i<MAX)
	{
		if(front[i]==-1)
		{
			i++;
		}
		else
		{
			printf("The value popped: %d", q[i][front[i]]);
			//q[i][front[i]]=0;
			f=1;
			if(front[i]==rear[i])
			{
				front[i]=-1;
				rear[i]=-1;
			}
			else
				front[i]=(front[i]+1)%MAX;
			break;
		}
	}
	if(f==0)
		printf("Queue Underflow\n");
}
void display(int q[MAX][MAX],int front[],int rear[])
{
	int i=0,j=0;
	printf("The queue looks like\n");
	for(i=0;i<MAX;i++)
	{
		if(front[i]!=-1)
		{
			if(front[i]<=rear[i])
			{
				for(j=front[i];j<=rear[i];j++)
				{
					printf("%d\t",q[i][j]);
				}	
				printf("\n");
			}
			else
			{
				for(j=front[i];j<MAX;j++)
				{
					printf("%d\t",q[i][j]);
				}	
				for(j=0;j<=rear[i];j++)
				{
					printf("%d\t",q[i][j]);
				}	
			}
		}
	}
	printf("\n");
}
void display1(int q[MAX][MAX])
{
	int i=0,j=0;
	printf("The queue looks like\n");
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			printf("%d\t",q[i][j]);
		}	
		printf("\n");
	}
}
void main()
{
	int n,val,pval,f;
	int q[MAX][MAX]={0};
	int front[MAX];
	int rear[MAX];
	memset(front,-1,sizeof(front));
	memset(rear,-1,sizeof(rear));
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Matrix representation\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value: ");
				scanf("%d", &val);
				fflush(stdin);
				printf("Enter the priority value: ");
				scanf("%d", &pval);
				pqInsert(q,front,rear,val,pval);
				break;
			}
			case 2: pqDelete(q,front,rear);
				break;
			case 3: display(q,front,rear);
				break;
			case 4: display1(q);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
