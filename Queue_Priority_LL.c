#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10
struct node
{
	int data,pv;
	struct node *next;
};
typedef struct node NODE;
NODE* getnode(int info,int p)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->next=NULL;
	newnode->data=info;
	newnode->pv=p;
	return(newnode);
}

/*SORTED*/

NODE* pqInsert(NODE *head,int *front,int *rear,int val,int pval)
{
	if((*rear+1)%MAX==*front)
		printf("Queue Overflow\n");
	else
	{
		if(head==NULL)
		{
			head=getnode(val,pval);
			*front=0;
		}
		else
		{
			NODE *ptr,*start;
			if(head->pv>pval)
			{
				ptr=getnode(val,pval);
				ptr->next=head;
				head=ptr;
			}
			else
			{
				start=head;
				while(start->next!=NULL && start->next->pv<=pval)
				{
					start=start->next;
				}
				ptr=getnode(val,pval);
				ptr->next=start->next;
				start->next=ptr;
			}
		}
		*rear=(*rear+1)%MAX;
	}
	return(head);
}
NODE* pqDelete(NODE *head,int *front,int *rear)
{
	if(*front==-1)
		printf("Queue Underflow\n");
	else
	{
		NODE *ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			*front=-1;
			*rear=-1;
		}
		else
		{
			ptr=head;
			head=head->next;
			ptr->next=NULL;
			*front=(*front+1)%MAX;
		}
		printf("The deleted value: %d\n",ptr->data);
		free(ptr);
	}
	return(head);
}

/*UNSORTED*/

NODE* pqInsert(NODE *head,int *front,int *rear,int val,int pval)
{
	if((*rear+1)%MAX==*front)
		printf("Queue Overflow\n");
	else
	{
		if(head==NULL)
		{
			head=getnode(val,pval);
			*front=0;
		}
		else
		{
			NODE *start;
			start=head;
			while(start->next!=NULL)
			{
				start=start->next;
			}
			start->next=getnode(val,pval);
		}
		*rear=(*rear+1)%MAX;
	}
	return(head);
}
NODE* pqDelete(NODE *head,int *front,int *rear)
{
	if(*front==-1)
		printf("Queue Underflow\n");
	else
	{
		NODE *min=head,*start;
		start=head;
		while(start->next!=NULL)
		{
			if(start->next->pv<min->pv)
				min=start->next;
			start=start->next;
		}
		start=head;
		while(min!=head && start->next!=min)
		{
			start=start->next;
		}
		if (min==head)
		{
			head=head->next;
		}
		else
		{
			start->next=min->next;
			min->next=NULL;
		}
		printf("The deleted value: %d\n",min->data);
		free(min);
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
			*front=(*front+1)%MAX;
	}
	return(head);
}


void Traverse(NODE *head,int *front,int *rear)
{
	if(*front==-1)
		printf("Queue Empty\n");
	else
	{
		printf("The elements of the Queue ");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
	}
}
void main()
{
	NODE* root;
	root=NULL;
	int n,val,pval,f;
	int front=-1;
	int rear=-1;
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value: ");
				scanf("%d", &val);
				fflush(stdin);
				printf("Enter the priority value: ");
				scanf("%d", &pval);
				root=pqInsert(root,&front,&rear,val,pval);
				break;
			}
			case 2: root=pqDelete(root,&front,&rear);
				break;
			case 3: Traverse(root,&front,&rear);
				break;
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
