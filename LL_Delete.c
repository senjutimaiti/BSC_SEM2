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
NODE* DeleteBeg(NODE* head)
{
	NODE *del;
	if(head==NULL)
	{
		printf("The linked list doesn't exist\n");
	}
	else
	{
		del=head;
		head=head->next;
		free(del);
	}
	return(head);
}
NODE* DeleteEnd(NODE* head)
{
	NODE *del,*start;
	start=head;
	if(head==NULL)
	{
		printf("The linked list doesn't exist\n");
	}
	else if(head->next==NULL)
	{
		del=head;
		head=head->next;
		free(del);
	}
	else
	{
		while(start->next->next!=NULL)
		{
			start=start->next;
		}
		del=start->next;
		start->next=NULL;
		free(del);
	}
	return(head);
}
NODE* DeleteNode(NODE* head,int info)
{
	NODE *del,*start;
	start=head;
	if(head==NULL)
	{
		printf("The linked list doesn't exist\n");
	}
	else
	{
		if(head->data==info)
		{
			del=head;
			head=head->next;
			free(del);
		}
		else
		{
			while(start->next!=NULL && start->next->data!=info)
			{
				start=start->next;
			}
			if(start->next==NULL)
			{
				printf("The node not found\n");
			}
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
	{
		printf("Incorrect node no.\n");
	}
	else
	{
		NODE* ptr;
		ptr=head;
		while(val>1 && ptr!=NULL)
		{
			ptr=ptr->next;
			val--;
		}
		if(ptr!=NULL)
		{
			head=DeleteNode(head,ptr->data);
		}
		else
		{
			printf("Node doesn't exist\n");
		}
	}
	return (head);
}
NODE* DeleteAfterNode(NODE* head,int info)
{
	NODE *del,*start;
	start=head;
	if(head==NULL)
	{
		printf("The linked list doesn't exist\n");
	}
	else
	{
		while(start->next!=NULL && start->data!=info)
		{
			start=start->next;
		}
		if(start->next==NULL)
		{
			printf("The node to be deleted not found\n");
		}
		else
		{
			del=start->next;
			start->next=del->next;
			free(del);
		}
	}
	return(head);
}
NODE* DeleteBeforeNode(NODE* head,int info)
{
	NODE *del,*start;
	start=head;
	if(head==NULL)
	{
		printf("The linked list doesn't exist\n");
	}
	else
	{
		if(start->data==info)
			printf("No node exist before for deleting\n");
		else if(start->next->data==info)
			head=DeleteBeg(head);
		else
		{
			while(start->next->next!=NULL && start->next->next->data!=info)
			{
				start=start->next;
			}
			if(start->next->next==NULL)
			{
				printf("The node not found\n");
			}
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
