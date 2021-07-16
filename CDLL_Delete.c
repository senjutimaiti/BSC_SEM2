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
		del=head;
		head=head->next;
		head->prev=del->prev;
		head->prev->next=head;
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
		del=head->prev;
		head->prev=del->prev;
		head->prev->next=head;
		free(del);
	}
	return(head);
}
NODE* DeleteNode(NODE* head,int info)
{
	NODE *del,*start;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else
	{
		if(head->data==info)
			head=DeleteBeg(head);
		else
		{
			start=head->next;
			while(start!=head && start->data!=info)
			{
				start=start->next;
			}
			if(start==head)
				printf("The node not found\n");
			else
			{
				del=start;
				start->next->prev=del->prev;
				start->prev->next=del->next;
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
			NODE *start=head->next,*del;
			while(val>2 && start!=head)
			{
				start=start->next;
				val--;
			}
			if(start!=head && val==2)
			{
				del=start;
				start->next->prev=del->prev;
				start->prev->next=del->next;
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
			start=start->next;
			del=start;
			start->next->prev=del->prev;
			start->prev->next=del->next;
			free(del);
		}
		else if(start->next==head && start->data==info)
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
		else
		{
			while(start->next!=head && start->next->data!=info)
			{
				start=start->next;
			}
			if(start->next->data==info)
			{
				del=start;
				if(start==head)
					head=head->next;
				start->next->prev=del->prev;
				start->prev->next=del->next;
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
