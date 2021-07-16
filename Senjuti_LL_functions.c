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
		NODE *start;
		start=head;
		while(start->next!=NULL)
			start=start->next;
		start->next=getnode(info);
	}
	return (head);
}
void Traverse(NODE *head)
{
	if(head==NULL)
		printf("Linked list empty\n");
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
/*search*/
int Search(NODE *head,int val)
{
	int f=0;
	if(head==NULL)
		printf("Linked list empty\n");
	else
	{
		while(head!=NULL)
		{
			if(head->data==val)
			{
				f=1;
				break;
			}
			head=head->next;
		}
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
/*Insertion*/
NODE* insertAtBeg(NODE *head,int info)
{
	NODE* ptr;
	ptr=getnode(info);
	ptr->next=head;
	head=ptr;
	return (head);
}
NODE* insertAtEnd(NODE *head,int info)
{
	if(head==NULL)
		head=getnode(info);
	else
	{
		NODE* ptr;
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=getnode(info);
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
		printf("The value not found\n");
	else
	{
		p=getnode(info);
		p->next=ptr->next;
		ptr->next=p;
	}
	return (head);
}
NODE* insertBeforeValue(NODE* head,int info,int val)
{
	NODE* ptr,*p;
	ptr=head;
	if(ptr->data==val)
		head=insertAtBeg(head,info);
	else
	{
		while(ptr->next!=NULL && ptr->next->data!=val)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
			printf("The value not found\n");
		else
		{
			p=getnode(info);
			p->next=ptr->next;
			ptr->next=p;
		}
	}
	return (head);
}
NODE* insertAfterNode(NODE* head,int info,int val)
{
	if(val<1)
		printf("Incorrect node no.\n");
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
			p=getnode(info);
			p->next=ptr->next;
			ptr->next=p;
		}
		else
			printf("Node doesn't exist\n");
	}
	return (head);
}
NODE* insertBeforeNode(NODE* head,int info,int val)
{
	if(val<1)
		printf("Incorrect node no.\n");
	else if(head!=NULL)
	{
		NODE* ptr,*p;
		ptr=head;
		while(val>2 && ptr->next!=NULL)
		{
			ptr=ptr->next;
			val--;
		}
		if(val==1)
			head=insertAtBeg(head,info);
		else if(ptr->next!=NULL)
		{
			p=getnode(info);
			p->next=ptr->next;
			ptr->next=p;
		}
		else
			printf("Node doesn't exist\n");
	}
	else
		printf("Linked list empty\n");
	return (head);
}
/*Deletion*/
NODE* DeleteBeg(NODE* head)
{
	NODE *del;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
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
		printf("The linked list doesn't exist\n");
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
		printf("The linked list doesn't exist\n");
	else
	{
		if(head->data==info)
			head=DeleteBeg(head);
		else
		{
			while(start->next!=NULL && start->next->data!=info)
			{
				start=start->next;
			}
			if(start->next==NULL)
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
		NODE* ptr,*del;
		ptr=head;
		while(val>2 && ptr->next!=NULL)
		{
			ptr=ptr->next;
			val--;
		}
		if(val==1)
			head=DeleteBeg(head);
		else if(ptr->next!=NULL)
		{
			del=ptr->next;
			ptr->next=del->next;
			free(del);	
		}
		else
			printf("Node doesn't exist\n");
	}
	else 
		printf("Linked list empty\n");
	return (head);
}
NODE* DeleteAfterNode(NODE* head,int info)
{
	NODE *del,*start;
	start=head;
	if(head==NULL)
		printf("The linked list doesn't exist\n");
	else
	{
		while(start->next!=NULL && start->data!=info)
		{
			start=start->next;
		}
		if(start->next==NULL)
			printf("The node to be deleted not found\n");
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
		printf("The linked list doesn't exist\n");
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
			printf("Do you want to enter again?(1/0) ");
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
