#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *prev,*next;
};
typedef struct node NODE;
NODE* getnode(NODE* head,int info)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->prev=head;
	newnode->data=info;
	newnode->next=NULL;
	return(newnode);
}
NODE* CreateLL(NODE *head,int info)
{
	if(head==NULL)
	{
		head=getnode(head,info);
		head->prev=head;
		head->next=head;
	}
	else
	{
		NODE *start=head->prev;
		start->next=getnode(start,info);
		start->next->next=head;
		head->prev=start->next;
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
			//printf("%d ",start->data);
			printf("\nprev=%u\nval=%d\nnext=%u\n",start->prev,start->data,start->next);
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
