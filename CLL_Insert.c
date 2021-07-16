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
			start=start->next;
		start->next=getnode(info);
		start->next->next=head;
	}
	return (head);
}
void Traverse(NODE *head)
{
	NODE *start=head;	
	if(head==NULL)
		printf("Linked List empty\n");
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
NODE* insertAtBeg(NODE *head,int info)
{
	NODE *ptr,*start=head;
	ptr=getnode(info);
	if(head==NULL)
		ptr->next=ptr;
	else
	{
		ptr->next=head;
		while(start->next!=head)
			start=start->next;
		start->next=ptr;
	}
	head=ptr;
	return (head);
}
NODE* insertAtEnd(NODE *head,int info)
{
	NODE *ptr,*start=head;
	ptr=getnode(info);
	if(head==NULL)
	{
		ptr->next=ptr;
		head=ptr;
	}
	else
	{
		ptr->next=head;
		while(start->next!=head)
			start=start->next;
		start->next=ptr;
	}
	return (head);
}
NODE* insertAfterValue(NODE* head,int info,int val)
{
	NODE* ptr,*start;
	start=head;
	if(head==NULL)
		printf("Linked List empty\n");
	else
	{
		do
		{
			if(start->data==val)
				break;
			start=start->next;
		}
		while(start!=head);
		if(start->data==val)
		{
			ptr=getnode(info);
			ptr->next=start->next;
			start->next=ptr;
		}
		else
			printf("The node not found\n");
	}
	return(head);
}
NODE* insertBeforeValue(NODE* head,int info,int val)
{
	NODE* ptr,*start;
	start=head;
	if(head==NULL)
		printf("Linked List empty\n");
	else if(head->data==val)
		head=insertAtBeg(head,info);
	else
	{
		do
		{
			start=start->next;
		}
		while(start!=head && start->next->data!=val);
		if(start->next->data==val)
		{
			ptr=getnode(info);
			ptr->next=start->next;
			start->next=ptr;
		}
		else
			printf("The node not found\n");
	}
	return (head);
}
NODE* insertAfterNode(NODE* head,int info,int val)
{
	if(val<1)
		printf("Incorrect node no.\n");
	else if(head!=NULL)
	{
		if(val==1)
			head=insertAfterValue(head,info,head->data);
		else
		{
			NODE *start=head,*ptr;
			while(val>1)
			{
				start=start->next;
				if(start==head)
					break;
				val--;
			}
			if(val==1)
			{
				ptr=getnode(info);
				ptr->next=start->next;
				start->next=ptr;
			}
			else
				printf("The node not found\n");
		}		
	}
	else
		printf("Linked List empty\n");
	return (head);
}
NODE* insertBeforeNode(NODE* head,int info,int val)
{
	if(val<1)
		printf("Incorrect node no.\n");
	else if(head!=NULL)
	{
		if(val==1)
			head=insertAtBeg(head,info);
		else
		{
			NODE *start=head,*ptr;
			while(val>2)
			{
				start=start->next;
				if(start==head)
					break;
				val--;
			}
			if(val==2 && start->next!=head)
			{
				ptr=getnode(info);
				ptr->next=start->next;
				start->next=ptr;
			}
			else
				printf("The node not found\n");
		}		
	}
	else
		printf("Linked List empty\n");
	return (head);
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
	else
	printf("The linked list is empty");
	/*Insertion*/
	printf("\nDo you want to insert an element in the linked list?(yes or no) ");
	fflush(stdin);
	scanf("%c", &ch);
	if(ch=='y')
	{
		while(1)
		{
			printf("Enter data: ");
			fflush(stdin);
			scanf("%d", &n);
			printf("Enter choice:\n1)At beginning\n2)At End\n3)After a value\n4)Before a value\n5)After Node no.\n6)Before Node no.\n");
			fflush(stdin);
			scanf("%d", &num);
			switch(num)
			{
				case 1: root=insertAtBeg(root,n);
				break;
				case 2: root=insertAtEnd(root,n);
				break;
				case 3: { printf("Enter the value after which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						root=insertAfterValue(root,n,val);
					break;
				}
				case 4: { printf("Enter the value before which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						root=insertBeforeValue(root,n,val);
					break;
				}
				case 5: { printf("Enter the node no. after which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						root=insertAfterNode(root,n,val);
					break;
				}
				case 6: { printf("Enter the node no. before which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						root=insertBeforeNode(root,n,val);
					break;
				}
				default: printf("Wrong choice\n");
			}
			Traverse(root);
			printf("\nDo you want to insert again?(1 or 0) ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
	}
}
