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
/*CLL creation*/
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
/*SEARCH*/
int Search(NODE *head,int val)
{
	NODE *start=head;
	int f=0;	
	if(head==NULL)
		printf("Linked List empty\n");
	else
	{
		do
		{
			if(start->data==val)
			{
				f=1;
				break;
			}
			start=start->next;
		}
		while(start!=head);
	}
	return f;
}
/*REVERSE*/
NODE* reverse_LL(NODE* head)
{
	NODE *H,*N,*P;
	if(head!=NULL)
	{
		H=head->next;
		N=H;
		P=head;
		P->next=NULL;
		while(N!=head)
		{
			N=N->next;
			H->next=P;
			P=H;
			H=N;
		}
		head->next=P;
		head=P;
	}
	else
		printf("The linked list is empty\n");
	return(head);
}
/*INSERTION*/
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
			if(start->next->data==val)
				break;
			start=start->next;
		}
		while(start!=head);
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
		NODE *start=head,*ptr;
		if(val==1)
		{
			ptr=getnode(info);
			ptr->next=start->next;
			start->next=ptr;
		}
		else
		{
			while(val>1)
			{
				start=start->next;
				if(start==head)
					break;
				val--;
			}
			if(start!=head)
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
		NODE *start=head,*ptr;
		if(val==1)
			head=insertAtBeg(head,info);
		else
		{
			while(val>2)
			{
				start=start->next;
				if(start->next==head)
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
/*DELETION*/
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
				if(start->next->data==info)
				break;
				start=start->next;
			}
			while(start->next!=head);
			if(start->next==head)
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
				if(start->next==head)
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
	else if(head->next!=head)
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
			head=DeleteBeg(head);
		else
			printf("The node not found\n");
	}
	else
		printf("No node exists after for deleting\n");
	return(head);
}
NODE* DeleteBeforeNode(NODE* head,int info)
{
	NODE *del,*start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else if(head->next!=head)
	{
		if(start->data==info)
			head=DeleteEnd(head);
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
	else
		printf("No node exists before for deleting\n");
	return(head);
}
void main()
{
	NODE* root;
	root=NULL;
	int n,num,f=1,val,flag; 
	char ch;
	printf("Do you want to create a linked list?(yes or no) ");
	scanf("%c", &ch);
	/*creating a linked list*/	
	if(ch=='y')
	{
		while(f==1)
		{
			printf("Enter data: ");
			fflush(stdin);
			scanf("%d", &n);
			root=CreateLL(root,n);
			printf("Do you want to enter again? ");
			fflush(stdin);
			scanf("%d", &f);	
		}
		Traverse(root);
	}
	else
	printf("The linked list is empty");
	/*Insertion and Deletion*/
	printf("\nDo you want to insert or delete an element in the linked list?(yes or no) ");
	fflush(stdin);
	scanf("%c", &ch);
	if(ch=='y')
	{
		while(1)
		{
			printf("Enter choice:\nINSERT:\n1)At beginning\n2)At End\n3)After a value\n4)Before a value\n5)After Node no.\n6)Before Node no.\nDELETE:\n7)Node value\n8)Node number\n9)First node\n10)Last node\n11)After node value\n12)Before node value\n13)Reverse\n14)Search\n");
			fflush(stdin);
			scanf("%d", &num);
			switch(num)
			{
				case 1:{
					printf("Enter data you want to insert: ");
					fflush(stdin);
					scanf("%d", &n);
					root=insertAtBeg(root,n);
					break;
				} 
				case 2: {
					printf("Enter data you want to insert: ");
					fflush(stdin);
					scanf("%d", &n);
					root=insertAtEnd(root,n);
					break;
				} 
				case 3: { printf("Enter the value after which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						printf("Enter data you want to insert: ");
						fflush(stdin);
						scanf("%d", &n);
						root=insertAfterValue(root,n,val);
					break;
				}
				case 4: { printf("Enter the value before which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						printf("Enter data you want to insert: ");
						fflush(stdin);
						scanf("%d", &n);
						root=insertBeforeValue(root,n,val);
					break;
				}
				case 5: { printf("Enter the node no. after which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						printf("Enter data you want to insert: ");
						fflush(stdin);
						scanf("%d", &n);
						root=insertAfterNode(root,n,val);
					break;
				}
				case 6: { printf("Enter the node no. before which you want to insert: ");
						fflush(stdin);
						scanf("%d", &val);
						printf("Enter data you want to insert: ");
						fflush(stdin);
						scanf("%d", &n);
						root=insertBeforeNode(root,n,val);
					break;
				}
				case 7: {	printf("Enter the value of the node to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteNode(root,n);
					break;
				}
				case 8: {	printf("Enter the number of the node to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteNodeNo(root,n);
					break;
				}
				case 9: root=DeleteBeg(root);
					break;
				case 10: root=DeleteEnd(root);
					break;
				case 11: {	printf("Enter the value of the node after which the node is to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteAfterNode(root,n);
					break;
				}
				case 12: {	printf("Enter the value of the node before which the node is to be deleted: ");
							fflush(stdin);
							scanf("%d", &n);
							root=DeleteBeforeNode(root,n);
					break;
				}
				case 13: root=reverse_LL(root);
					break;
				case 14:{
					printf("Enter data you want to search: ");
					fflush(stdin);
					scanf("%d", &n);
					flag=Search(root,n);
					if(flag==1)
						printf("\nThe number is found\n");
					else
						printf("\nThe number is not found\n");
					break;
				} 
				default: printf("Wrong choice\n");
			}
			Traverse(root);
			printf("\nDo you want to edit again?(1 or 0) ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
	}
}
