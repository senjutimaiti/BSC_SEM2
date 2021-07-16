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
NODE* getnode(int info)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->next=NULL;
	newnode->data=info;
	return(newnode);
}
NODE* push(NODE *head,int info,int *top)
{
	//printf("top=%d\n",*top);
	if(*top==MAX-1)
		printf("Stack Overflow\n");
	else
	{
		if(head==NULL)
		{
			head=getnode(info);
		}
		else
		{
			NODE *start;
			start=head;
			while(start->next!=NULL)
			{
				start=start->next;
			}
			start->next=getnode(info);
		}
		*top=*top+1;
	}
	return(head);
}
NODE* pop(NODE *head,int *top)
{
	//printf("top=%d\n",*top);
	if(*top==-1)
		printf("Stack Underflow\n");
	else
	{
		NODE *start,*ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
		}
		else
		{
			start=head;
			while(start->next->next!=NULL)
			{
				start=start->next;
			}
			ptr=start->next;
			start->next=NULL;
		}
		printf("The popped value: %d\n",ptr->data);
		free(ptr);
		*top=*top-1;
	}
	return(head);
}
NODE* peek(NODE *head,int *top)
{
	//printf("top=%d\n",*top);
	if(*top==-1)
		printf("Stack Underflow\n");
	else
	{
		NODE *start;
		start=head;
		while(start->next!=NULL)
		{
			start=start->next;
		}
		printf("The peeked value: %d\n",start->data);
	}
	return(head);
}
void Traverse(NODE *head,int *top)
{
	//printf("top=%d\n",*top);
	if(*top==-1)
		printf("Stack Empty\n");
	else
	{
		printf("The elements of the stack ");
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
	int n,f,value,top=-1;
	do
	{
		printf("1. push\n2. pop\n3. peek\n4. display\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
				printf("Enter the value to be pushed: ");
				scanf("%d", &value);
				root=push(root,value,&top);
				break;
			}
			case 2: root=pop(root,&top);
				break;
			case 3: root=peek(root,&top);
				break;
			case 4: Traverse(root,&top);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
	while(f==1);
}
