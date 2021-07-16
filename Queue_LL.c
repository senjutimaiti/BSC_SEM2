#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 5
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
/*NODE* getnode(int info)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->next=NULL;
	newnode->data=info;
	return(newnode);
}
NODE* enqueue(NODE *head,NODE **front,NODE **rear,int info)
{
	if((*rear)->data==MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if((*front)->data==-1)
		{
			head=getnode(info);
			(*front)->data=0;
			(*front)->next=head;
			(*rear)->next=head;
		}
		else
		{
			NODE *ptr=getnode(info);
			(*rear)->next->next=ptr;
			(*rear)->next=ptr;
		}
		(*rear)->data=(*rear)->data+1;
	}
	return(head);
}
NODE* dequeue(NODE *head,NODE **front,NODE **rear)
{
	if((*front)->data==-1)
		printf("Queue Underflow\n");
	else
	{
		NODE *ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			(*front)->data=-1;
			(*front)->next=NULL;
			(*rear)->next=NULL;
		}
		else
		{
			ptr=head;
			head=head->next;
			(*front)->next=head;
		}
		printf("The deleted value: %d\n",ptr->data);
		(*rear)->data=(*rear)->data-1;
		free(ptr);
	}
	return(head);
}
void Traverse(NODE *head)
{
	if(head==NULL)
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
	NODE *root,*front,*rear;
	root=NULL;
	int n,value,f=1;
	front=getnode(-1);
	rear=getnode(-1);
	while(f==1)
	{
		printf("1. enqueue\n2. dequeue\n3. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				root=enqueue(root,&front,&rear,value);
				break;
			}
			case 2: root=dequeue(root,&front,&rear);
				break;
			case 3: Traverse(root);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
}*/
NODE* getnode()
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->next=NULL;
	return(newnode);
}
NODE* enqueue(NODE *head,NODE **front,NODE **rear,int info)
{
	NODE *ptr=NULL;
	ptr=getnode();
	if(ptr==NULL)
		printf("Queue Overflow\n");
	else
	{
		if(*front==NULL)
		{
			ptr->data=info;
			head=ptr;
			*front=head;
			*rear=head;
		}
		else
		{
			ptr->data=info;
			(*rear)->next=ptr;
			*rear=ptr;
		}
	}
	return(head);
}
NODE* dequeue(NODE *head,NODE **front,NODE **rear)
{
	if(head==NULL)
		printf("Queue Underflow\n");
	else
	{
		NODE *ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			*front=NULL;
			*rear=NULL;
		}
		else
		{
			ptr=head;
			head=head->next;
			*front=head;
		}
		printf("The deleted value: %d\n",ptr->data);
		free(ptr);
	}
	return(head);
}
void Traverse(NODE *head)
{
	if(head==NULL)
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
	NODE *root,*front,*rear;
	root=NULL;
	int n,value,f=1;
	front=NULL;
	rear=NULL;
	while(f==1)
	{
		printf("1. enqueue\n2. dequeue\n3. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				root=enqueue(root,&front,&rear,value);
				break;
			}
			case 2: root=dequeue(root,&front,&rear);
				break;
			case 3: Traverse(root);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
}
