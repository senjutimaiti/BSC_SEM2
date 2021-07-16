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
		printf("The elements of the linked list ");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
	}
}
NODE* merge(NODE *root1,NODE *root2)
{
	NODE *p,*root;
	root=root1;
	while(root1->next!=NULL && root2->next!=NULL)
	{
		if(root2->data <= root1->next->data)
		{
			p=root2;
			root2=root2->next;
			p->next=root1->next;
			root1->next=p;
		}
		root1=root1->next;
	}
	if(root2->next==NULL)
	{
		while(root1->next!=NULL && root2->data > root1->next->data)
		{
			root1=root1->next;
		}
		root2->next=root1->next;
		root1->next=root2;
	}
	else
	{
		root1->next=root2;
	}
	p=NULL;
	return(root);
}
void main()
{
	NODE *root1,*root2,*root;
	root1=NULL;
	root2=NULL;
	int n,num,f,val; 
	while(1)
	{
		printf("Enter data: ");
		fflush(stdin);
		scanf("%d", &n);
		root1=CreateLL(root1,n);
		printf("Do you want to enter again? ");
		fflush(stdin);
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}	
	}
	Traverse(root1);
	printf("\n");
	while(1)
	{
		printf("Enter data: ");
		fflush(stdin);
		scanf("%d", &n);
		root2=CreateLL(root2,n);
		printf("Do you want to enter again? ");
		fflush(stdin);
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}	
	}
	Traverse(root2);
	printf("\n");
	if(root1->data > root2->data)
		root=merge(root2,root1);
	else
		root=merge(root1,root2);
	printf("\nAfter merging\n");
	Traverse(root);
}
