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
NODE* insertAtBeg(NODE *head,int info)
{
	NODE* ptr=NULL;
	ptr=getnode(ptr,info);
	ptr->next=head;
	if(head!=NULL)
		head->prev=ptr;
	head=ptr;
	return (head);
}
NODE* insertAtEnd(NODE *head,int info)
{
	if(head==NULL)
	{
		head=insertAtBeg(head,info);
	}
	else
	{
		NODE* ptr;
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=getnode(ptr,info);
	}
	return (head);
}
NODE* insertAfterValue(NODE* head,int info,int val)
{
	NODE* ptr,*p;
	ptr=head;
	while(ptr!=NULL && ptr->data!=val)
	{
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("The value not found\n");
	}
	else
	{
		p=getnode(ptr,info);
		p->next=ptr->next;
		if(ptr->next!=NULL)
			ptr->next->prev=p;
		ptr->next=p;
	}
	return (head);
}
NODE* insertBeforeValue(NODE* head,int info,int val)
{
	NODE* ptr,*p;
	ptr=head;
	while(ptr!=NULL && ptr->data!=val)
	{
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("The value not found\n");
	}
	else
	{
		p=getnode(ptr->prev,info);
		p->next=ptr;
		if(ptr->prev!=NULL)
			ptr->prev->next=p;
		else
			head=p;
		ptr->prev=p;
	}
	return (head);
}
NODE* insertAfterNode(NODE* head,int info,int val)
{
	if(val<1)
	{
		printf("Incorrect node no.\n");
	}
	else
	{
		NODE* ptr,*p;
		ptr=head;
		while(val>1 && ptr!=NULL)
		{
			ptr=ptr->next;
			val--;
		}
		if(ptr!=NULL)
		{
			p=getnode(ptr,info);
			p->next=ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev=p;
			ptr->next=p;
		}
		else
		{
			printf("Node doesn't exist\n");
		}
	}
	return (head);
}
NODE* insertBeforeNode(NODE* head,int info,int val)
{
	if(val<1)
	{
		printf("Incorrect node no.\n");
	}
	else
	{
		NODE* ptr,*p;
		ptr=head;
		while(val>1 && ptr!=NULL)
		{
			ptr=ptr->next;
			val--;
		}
		if(ptr!=NULL)
		{
			p=getnode(ptr->prev,info);
			p->next=ptr;
			if(ptr->prev!=NULL)
				ptr->prev->next=p;
			else
				head=p;
			ptr->prev=p;
		}
		else
		{
			printf("Node doesn't exist\n");
		}
	}
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
