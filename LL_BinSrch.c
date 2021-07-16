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
NODE* middle(NODE* start,NODE* end)
{
	int f=1;
	NODE* head;
	head=start;
	while(start!=end)
	{
		start=start->next;
		f++;
	}
	f=f/2;
	while(f>1)
	{
		head=head->next;
		f--;
	}
	start=NULL;
	return(head);
}
void BinSearch(NODE* head,int key)
{
	int f=0;
	NODE *start,*end,*mid;
	start=head;
	end=head;
	mid=NULL;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	while(start!=NULL && end!=NULL && start->data<=end->data)
	{
		mid=middle(start,end);
		if(mid->data==key)
		{
			f=1;
			break;
		}
		else if(mid->data>key)
		{
			end=mid;
		}
		else
		{
			start=mid->next;
		}
	}
	if(f==1)
		printf("the number is found");
	else
		printf("the number is not found");	
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
	while(1)
	{
		printf("\nEnter the number to be searched ");
		fflush(stdin);
		scanf("%d",&val);
		if(val<root->data)
			printf("the number is not found");
		else
			BinSearch(root,val);
		printf("\nDo you want to search again? ");
		fflush(stdin);
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}
	}
}
