#include <stdio.h>
#include <stdlib.h>
void display(int n, int a[n])
{
	int i,j;
	for(i=0;i<n;i++)
	printf("%d\t", a[i]);
	printf("\n");
}
void arrange(int *a, int n, int i)
{
	int max=i,temp;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[max])
		max=l;
	if(r<n && a[r]>a[max])
		max=r;
	if(max!=i)
	{
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		arrange(a,n,max);
	}
}
void heap_a(int *a,int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
		arrange(a,n,i);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		arrange(a,i,0);
	}
}
void arrange2(int *a, int n, int i)
{
	int min=i,temp;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]<a[min])
		min=l;
	if(r<n && a[r]<a[min])
		min=r;
	if(min!=i)
	{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		arrange2(a,n,min);
	}
}
void heap(int *a,int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
		arrange2(a,n,i);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		arrange2(a,i,0);
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
		heap_a(a,n);
		printf("\nAscending order: ");
		display(n,a);
		heap(a,n);
		printf("\nDescending order: ");
		display(n,a);
	}
	else
	printf("Wrong Input");
}
