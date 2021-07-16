#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data,pow;
	struct node *next;
};
typedef struct node NODE;
NODE* getnode(int info,int pow)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=info;
	newnode->pow=pow;
	newnode->next=NULL;
	return(newnode);
}
NODE* getnode1()
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->next=NULL;
	return(newnode);
}
NODE* CreateLL(NODE *head,int info,int pow)
{
	if(head==NULL)
		head=getnode(info,pow);
	else
	{
		NODE *start;
		start=head;
		while(start->next!=NULL)
			start=start->next;
		start->next=getnode(info,pow);
	}
	return (head);
}
void Traverse(NODE *head)
{
	printf("\nThe polynomial ");
	while(head!=NULL)
	{
		printf("%dx^%d ",head->data,head->pow);
		head=head->next;
	}
}
void swap(NODE** p1,NODE** p2)
{
	NODE* t;
	t=*p1;
	*p1=*p2;
	*p2=t;
}
NODE* polyAdd(NODE* p1,NODE* p2)
{
	NODE *res,*x;
	res=NULL;
	while(p1!=NULL & p2!=NULL)
	{
		if(p1->pow<p2->pow)
			swap(&p1,&p2);
		if(res==NULL)
		{
			res=getnode1();
			x=res;
		}
		else
		{
			x->next=getnode1();
			x=x->next;
		}
		if(p1->pow==p2->pow)
		{
			x->data=p1->data+p2->data;
			x->pow=p1->pow;
			p1=p1->next;
			p2=p2->next;
		}
		else
		{
			x->data=p1->data;
			x->pow=p1->pow;
			p1=p1->next;
		}
	}
	while(p1!=NULL)
	{
		x->next=getnode1();;
		x=x->next;
		x->data=p1->data;
		x->pow=p1->pow;
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		x->next=getnode1();;
		x=x->next;
		x->data=p2->data;
		x->pow=p2->pow;
		p2=p2->next;
	}
	return(res);
}
NODE* polyMulti(NODE* p1,NODE* p2)
{
	NODE *res=NULL,*x,*y,*ph;
	while(p1!=NULL)
	{
		ph=p2;
		while(ph!=NULL)
		{
			if(res==NULL)
			{
				res=getnode1();
				x=res;
			}
			else
			{
				x->next=getnode1();
				x=x->next;
			}
			x->data=ph->data*p1->data;
			x->pow=ph->pow+p1->pow;
			ph=ph->next;
		}
		p1=p1->next;
	}
	x=res;
	res=NULL;
	while(x!=NULL)
	{
		if(x->pow==-99)
		{
			x=x->next;
			continue;
		}
		if(res==NULL)
		{
			res=getnode1();
			y=res;
		}
		else
		{
			y->next=getnode1();
			y=y->next;
		}
		ph=x->next;
		y->data=x->data;
		y->pow=x->pow;
		while(ph!=NULL)
		{
			if(ph->pow==y->pow)
			{
				y->data=y->data+ph->data;
				ph->pow=-99;
			}
			ph=ph->next;
		}
		x=x->next;
	}
	return(res);
}
void main()
{
	NODE *root1,*root2,*res,*pro;
	root1=NULL;
	root2=NULL;
	int n,p,f; 
	//First polynomial
	printf("Enter the first polynomial\n");
		while(1)
		{
			printf("Enter the coefficient and power respectively: ");
			fflush(stdin);
			scanf("%d", &n);
			fflush(stdin);
			scanf("%d", &p);
			root1=CreateLL(root1,n,p);
			printf("Do you want to enter again? ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
		Traverse(root1);
	//Second polynomial
	printf("\nEnter the second polynomial\n");
		while(1)
		{
			printf("Enter the coefficient and power respectively: ");
			fflush(stdin);
			scanf("%d", &n);
			fflush(stdin);
			scanf("%d", &p);
			root2=CreateLL(root2,n,p);
			printf("Do you want to enter again? ");
			fflush(stdin);
			scanf("%d", &f);
			if(f!=1)
			{
				break;
			}	
		}
		Traverse(root2);
	res=polyAdd(root1,root2);
	printf("\nThe polynomial after addition");
	Traverse(res);	
	pro=polyMulti(root1,root2);
	printf("\nThe polynomial after multiplication");
	Traverse(pro);	
}
