#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int linsearch(int a[],int n,int val)
{
	int i,pos=-1;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
		{
			pos=i;
			break;
		}
	}
	return pos;		
}
void InsertBefore(int a[],int *n,int val,int pos)
{
	pos=linsearch(a,*n,pos);
	if(pos==-1)
		printf("Element not found\n");
	else
		Insert(a,n,val,(pos+1));
}
void InsertAfter(int a[],int *n,int val,int pos)
{
	pos=linsearch(a,*n,pos);
	if(pos==-1)
		printf("Element not found\n");
	else
		Insert(a,n,val,(pos+2));
}
void Insert(int a[],int *n,int val,int pos)
{
	int i;
	if(pos<1 || pos>*n+1)
		printf("Incorrect position");
	else
	{
		if(pos==*n+1)
			a[*n]=val;
		else
		{
			for(i=*n;i>=pos;i--)
				a[i]=a[i-1];
			a[pos-1]=val;
		}
		*n=*n+1;
		printf("The array after insertion: ");
		for(i=0;i<*n;i++)
			printf("%d ",a[i]);
	}
}
void main()
{
	int a[MAX],n,i,val,pos,f=1,num;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(f)
	{
		printf("1. Insert at a given position\n2. Insert after a given element\n3. Insert before a given element\nEnter your choice: ");
		scanf("%d",&num);
		printf("Enter the element you want to insert ");
		scanf("%d",&val);
		switch(num)
		{
			case 1:{printf("Enter the position: ");
					scanf("%d",&pos);
					Insert(a,&n,val,pos);
				break;
			}
			case 2:{printf("Enter the value after which you want to insert: ");
					scanf("%d",&pos);
					InsertAfter(a,&n,val,pos);
				break;
			}
			case 3:{printf("Enter the value before which you want to insert: ");
					scanf("%d",&pos);
					InsertBefore(a,&n,val,pos);
				break;
			}
			default: printf("Wrong choice\n");
		}
		printf("\nDo you want to continue? ");
		scanf("%d",&f);
	}
}
