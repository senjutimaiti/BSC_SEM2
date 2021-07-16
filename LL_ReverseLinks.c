#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *root1=NULL;
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
		head=getnode(info);	
	else
	{
		NODE *start=head;
		while(start->next!=NULL)
			start=start->next;
		start->next=getnode(info);
	}
	return (head);
}
void Traverse(NODE *head)
{
	if(head==NULL)
		printf("Linked List empty\n");
	else
	{
		printf("\nThe elements of the linked list ");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
	}
}
/*Reversing links using recursive function*/
NODE* reverse_LL(NODE* head)
{
	if(head->next==NULL)
	{
		root1=head;
		return(head);
	}
	else
	{
		NODE* node=reverse_LL(head->next);
		node->next=head;
		head->next=NULL;
		return(head);
	}
}
/*Reversing links without using recursive function*/
NODE* reverse_LLL(NODE* head)
{
	NODE *H,*N,*P;
	if(head!=NULL)
	{
		H=head->next;
		N=H;
		P=head;
		P->next=NULL;
		while(N!=NULL)
		{
			N=N->next;
			H->next=P;
			P=H;
			H=N;
		}
		head=P;
	}
	else
		printf("The linked list is empty\n");
	return(head);
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
	reverse_LL(root);
	//root1=reverse_LLL(root);
	Traverse(root1);
}
