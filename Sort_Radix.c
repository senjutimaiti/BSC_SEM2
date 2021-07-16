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
void display(int n, int a[n])
{
	int i,j;
	for(i=0;i<n;i++)
	printf("%d ", a[i]);
}
void radix(int *a,int n)
{
	int i,m=a[0],exp=1,l;
	for(i=1;i<n;i++)
	{
		if(a[i]>m)
			m=a[i];
	}
	while(m/exp>0)
	{
		NODE *head=NULL,*ptr=NULL,*start;
		NODE* buc[10]={NULL};
		for(i=0;i<n;i++)
		{
			l=(a[i]/exp)%10;
			ptr=getnode(a[i]);
			if(buc[l]==NULL)
				buc[l]=ptr;
			else
			{
				start=buc[l];
				while(start->next!=NULL)
					start=start->next;
				start->next=ptr;
			}
		}
		i=0;
		while(buc[i]==NULL)
			i++;
		head=buc[i];
		l=0;
		while(i<10)
		{
			while(head!=NULL)
			{
				a[l++]=head->data;
				head=head->next;
			}
			i++;
			while(buc[i]==NULL)
				i++;
			head=buc[i];
		}
		exp*=10;
	}
}
main()
{
	int n,i,f,num;
	printf("Enter the number of elements ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements ");
	for(i=0;i<n;i++)
	scanf("%d", &a[i]);
	if(n>0)
	{
		radix(a,n);
		printf("The array after sorting ");
		display(n,a);
	}
	else
	printf("Wrong Input");
}
