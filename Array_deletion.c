#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void Delete(int a[],int *n,int del)
{
	int i,p=0;
	for(i=0;i<*n;i++)
	{
		while(a[i]==del)
			i++;
		a[p++]=a[i];
	}
	if(p==*n)
		printf("The element not found");
	else
	{
		*n=p;
		printf("The elements after deletion: ");
		for(i=0;i<*n;i++)
			printf("%d ",a[i]);
	}
}
void DeletePos(int a[],int *n,int del)
{
	if(del>*n || del<1)
		printf("Incorrect position no.\n");
	else
	{
		int i;
		for(i=del-1;i<*n-1;i++)
			a[i]=a[i+1];
		*n=*n-1;
		printf("The elements after deletion: ");
		for(i=0;i<*n;i++)
			printf("%d ",a[i]);	
	}
}
void main()
{
	int a[MAX],n,i,del,f=1,num;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(f)
	{
		printf("1. Delete a number\n2. Delete from a given position\nEnter your choice: ");
		scanf("%d",&num);
		printf("Enter the element/position accordingly: ");
		scanf("%d",&del);
		switch(num)
		{
			case 1:	Delete(a,&n,del);
			break;
			case 2: DeletePos(a,&n,del);
			break;
			default: printf("Wrong choice\n");
		}
		printf("\nDo you want to continue? ");
		scanf("%d",&f);
	}
}
