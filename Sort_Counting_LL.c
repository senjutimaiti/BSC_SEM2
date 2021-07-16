#include <stdio.h>
#include <stdlib.h>
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
		printf("\nThe elements of the linked list ");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
	}
	printf("\n");
}
NODE* reverse(NODE *head)
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
NODE *radix(NODE *head,int n)
{
	int i,exp=1,b[n];
	NODE *start, *max;
	start=head->next;
	max=head;
	while(start!=NULL)
	{
		if(start->data>max->data)
			max=start;
		start=start->next;
	}
	while(max->data/exp>0)
	{
		start=head;
		int buc[10]={0};
		while(start!=NULL)
		{
			buc[(start->data/exp)%10]++;
			start=start->next;
		}
		for(i=1;i<10;i++)
			buc[i]+=buc[i-1];
		start=reverse(head);
		head=start;
		while(start!=NULL)
		{
			b[--buc[(start->data/exp)%10]]=start->data;
			start=start->next;
		}
		start=head;
		i=0;
		while(start!=NULL)
		{
			start->data=b[i];
			start=start->next;
			i++;
		}
		exp*=10;
	}
	return (head);
}
main()
{
	NODE* root;
	root=NULL;
	int n,f,i,num;
	printf("Enter the number of elements ");
	scanf("%d", &num);
	f=num;
	printf("Enter the elements ");
	while(f>0)
	{
		fflush(stdin);
		scanf("%d", &n);
		root=CreateLL(root,n);
		f--;	
	}
	Traverse(root);
	if(num>0)
	{
		root=radix(root,num);
		printf("After sorting ");
		Traverse(root);
	}
	else
	printf("Wrong Input");
}
