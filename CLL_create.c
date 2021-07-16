#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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
	newnode->data=info;
	newnode->next=NULL;
	return(newnode);
}
NODE* CreateLL(NODE *head,int info)
{
	if(head==NULL)
	{
		head=getnode(info);
		head->next=head;
	}
	else
	{
		NODE *start;
		start=head;
		while(start->next!=head)
		{
			start=start->next;
		}
		start->next=getnode(info);
		start->next->next=head;
	}
	return (head);
}
void Traverse(NODE *head)
{
	NODE *start=head;	
	if(head==NULL)
		printf("Linked List empty");
	else
	{
		printf("The elements of the linked list ");
		do
		{
			printf("%d ",start->data);
			start=start->next;
		}
		while(start!=head);
	}
}
void main()
{
	NODE* root;
	root=NULL;
	int n,f;
	while(1)
	{
		printf("Enter data: ");
		fflush(stdin);
		scanf("%d", &n);
		root=CreateLL(root,n);
		printf("Do you want to enter again? ");
		fflush(stdin);
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}	
	}
	Traverse(root);	
}
