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
NODE* push(NODE *head,int info,NODE **top)
{
	if((*top)->data==MAX-1)
		printf("Stack Overflow\n");
	else
	{
		if(head==NULL)
		{
			head=getnode(info);
			(*top)->next=head;
		}
		else
		{
			NODE* ptr=getnode(info);
			(*top)->next->next=ptr;
			(*top)->next=ptr;
		}
		(*top)->data=(*top)->data+1;
	}
	return(head);
}
NODE* pop(NODE *head,NODE **top)
{
	if((*top)->data==-1)
		printf("Stack Underflow\n");
	else
	{
		NODE *start,*ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			(*top)->next=head;
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
			(*top)->next=start;
		}
		printf("The popped value: %d\n",ptr->data);
		free(ptr);
		(*top)->data=(*top)->data-1;
	}
	return(head);
}
void peek(NODE **top)
{
	if((*top)->data==-1)
		printf("Stack Underflow\n");
	else
		printf("The peeked value: %d\n",(*top)->next->data);
}
void Traverse(NODE *head,NODE **top)
{
	if((*top)->data==-1)
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
	NODE *root,*top;
	root=NULL;
	int n,f=1,value;
	top=getnode(-1);
	while(f==1)
	{
		printf("1. push\n2. pop\n3. peek\n4. display\nEnter your choice: ");
		fflush(stdin);
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
			case 3: peek(&top);
				break;
			case 4: Traverse(root,&top);
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
NODE* push(NODE *head,int info,NODE **top)
{
	NODE *ptr=NULL;
	ptr=getnode();
	if(ptr==NULL)
		printf("Stack Overflow\n");
	else
	{
		if(head==NULL)
		{
			head=ptr;
			ptr->data=info;
			*top=head;
		}
		else
		{
			ptr->data=info;
			(*top)->next=ptr;
			*top=ptr;
		}
	}
	return(head);
}
NODE* pop(NODE *head,NODE **top)
{
	if(head==NULL)
		printf("Stack Underflow\n");
	else
	{
		NODE *start,*ptr;
		if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			*top=NULL;
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
			*top=start;
		}
		printf("The popped value: %d\n",ptr->data);
		free(ptr);
	}
	return(head);
}
void peek(NODE *top)
{
	if(top==NULL)
		printf("Stack Underflow\n");
	else
		printf("The peeked value: %d\n",top->data);
}
void Traverse(NODE *head)
{
	if(head==NULL)
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
	NODE *root,*top;
	root=NULL;
	int n,f=1,value;
	top=NULL;
	while(f==1)
	{
		printf("1. push\n2. pop\n3. peek\n4. display\nEnter your choice: ");
		fflush(stdin);
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
			case 3: peek(top);
				break;
			case 4: Traverse(root);
				break;	
			default: printf("Wrong input choice");
		}
		printf("\nEnter 1 to continue ");
		scanf("%d",&f);
	}
}
