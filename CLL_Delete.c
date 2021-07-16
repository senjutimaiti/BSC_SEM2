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
NODE* DeleteBeg(NODE* head)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else if(head->next==head)
	{
		del=head;
		head=NULL;
		free(del);
	}
	else
	{
		while(start->next!=head)
		{
			start=start->next;
		}
		del=head;
		head=head->next;
		start->next=head;
		free(del);
	}
	return(head);
}
NODE* DeleteEnd(NODE* head)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else if(head->next==head)
	{
		del=head;
		head=NULL;
		free(del);
	}
	else
	{
		while(start->next->next!=head)
		{
			start=start->next;
		}
		del=start->next;
		start->next=head;
		free(del);
	}
	return(head);
}
NODE* DeleteNode(NODE* head,int info)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else
	{
		if(head->data==info)
			head=DeleteBeg(head);
		else
		{
			do
			{
				start=start->next;
			}
			while(start!=head && start->next->data!=info);
			if(start==head)
				printf("The node not found\n");
			else
			{
				del=start->next;
				start->next=del->next;
				free(del);
			}
		}
	}
	return(head);
}
NODE* DeleteNodeNo(NODE* head,int val)
{
	if(val<1)
		printf("Incorrect node no.\n");
	else if(head!=NULL)
	{
		if(val==1)
			head=DeleteBeg(head);
		else
		{
			NODE *start=head,*del;
			while(val>2)
			{
				start=start->next;
				if(start==head)
					break;
				val--;
			}
			if(start->next!=head && val==2)
			{
				del=start->next;
				start->next=del->next;
				free(del);
			}
			else
				printf("The node not found\n");
		}		
	}
	else
		printf("The linked list doesn't exist\n");
	return (head);
}
NODE* DeleteAfterNode(NODE* head,int info)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else
	{
		do
		{
			if(start->data==info)
				break;
			start=start->next;
		}
		while(start!=head);
		if(start->data==info && start->next!=head) 
		{
			del=start->next;
			start->next=del->next;
			free(del);
		}
		else if(start->next==head)
			printf("No node exist after for deleting\n");
		else
			printf("The node not found\n");
	}
	return(head);
}
NODE* DeleteBeforeNode(NODE* head,int info)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else
	{
		if(start->data==info)
			printf("No node exist before for deleting\n");
		else if(start->next->data==info)
			head=DeleteBeg(head);
		else
		{
			while(start->next->next!=head && start->next->next->data!=info)
			{
				start=start->next;
			}
			if(start->next->next->data==info)
			{
				del=start->next;
				start->next=del->next;
				free(del);
			}
			else
				printf("The node not found\n");
		}
	}
	return(head);
}
void main()
{
	NODE* root;
	root=NULL;
	int n,num,f,val; 
	char ch;
	printf("Do you want to create a linked list?(yes or no) ");
	scanf("%c", &ch);
	/*creating a linked list*/	
	if(ch=='y')
	{
		while(1)
		{
			printf("Enter data: ");
			fflush(stdin);
			scanf("%d", &n);
			root=CreateLL(root,n);
			printf("Do you want to enter again?(1 or 0) ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
		Traverse(root);
	}
	else
	printf("The linked list is empty");
	/*Deleting*/
	printf("\nDo you want to delete an element from the linked list?(yes or no) ");
	fflush(stdin);
	scanf("%c", &ch);
	if(ch=='y')
	{
		while(1)
		{
			printf("Enter choice:\n1)Delete node value\n2)Delete node number\n3)Delete first node\n4)Delete last node\n5)Delete after node\n6)Delete before node\n");
			fflush(stdin);
			scanf("%d", &num);
			switch(num)
			{
				case 1: {	printf("Enter the value of the node to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteNode(root,n);
					break;
				}
				case 2: {	printf("Enter the number of the node to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteNodeNo(root,n);
					break;
				}
				case 3: root=DeleteBeg(root);
					break;
				case 4: root=DeleteEnd(root);
					break;
				case 5: {	printf("Enter the value of the node after which the node is to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteAfterNode(root,n);
					break;
				}
				case 6: {	printf("Enter the value of the node before which the node is to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteBeforeNode(root,n);
					break;
				}
				default: printf("Wrong choice\n");
			}
			Traverse(root);
			printf("\nDo you want to delete again?(1 or 0) ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
	}
}
