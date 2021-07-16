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
	}
	else
	{
		NODE *start;
		start=head;
		while(start->next!=NULL)
		{
			start=start->next;
		}
		start->next=getnode(start,info);
	}
	return (head);
}
void Traverse(NODE *head)
{
	printf("The elements of the linked list ");
	while(head!=NULL)
	{
		//printf("%d ",head->data);
		printf("\nprev=%u\ndata=%d\nnext=%u\n",head->prev,head->data,head->next);
		head=head->next;
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
