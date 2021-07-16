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
		printf("\nThe elements of the linked list ");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
	}
}
NODE* BubSort(NODE *head)
{
	int c=0;
	NODE *start=head;
	if(head==NULL)
		printf("Linked list empty\n");
	else
	{
		for(;start!=NULL;start=start->next)
			c++;
		/*int k,temp;
		while(c>1)
		{
			k=c;
			start=head;
			while(k>1)
			{
				if((start->data) > (start->next->data))
				{
					temp=start->data;
					start->data=start->next->data;
					start->next->data=temp;
				}
				start=start->next;
				k--;	
			}
			c--;
		}
		*/
		int m,n,temp;
		for(m=1;m<c;m++)
		{
			for(n=1,start=head;n<=c-m;n++,start=start->next)
			{
				if((start->data) > (start->next->data))
				{
					temp=start->data;
					start->data=start->next->data;
					start->next->data=temp;
				}
			}
		}
	}
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
			break;	
	}
	Traverse(root);	
	root=BubSort(root);
	Traverse(root);	
}
