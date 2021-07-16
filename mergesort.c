#include <stdio.h>
#include <stdlib.h>
# define SIZE 20
void display(int n, int a[n])
{
	int i,j;
	for(i=0;i<n;i++)
	printf("%d\t", a[i]);
	printf("\n");
}
void mergesort(int a[],int m,int n)
{
	int mid;
	if(m<n)
	{
		mid=(m+n)/2;
		mergesort(a,m,mid);
		mergesort(a,mid+1,n);
		merge(a,m,mid,n);
	}
}
void merge(int a[],int m,int mid,int n)
{
	int x[SIZE],i=m,j=mid+1,k=0;
	while(i<=mid && j<=n)
	{
		if(a[i]>a[j])
		{
			x[k]=a[j];
			j++;
		}
		else if(a[i]<a[j])
		{
			x[k]=a[i];
			i++;
		}
		k++;
	}
	for(;i<=mid;i++,k++)
	{
		x[k]=a[i];
	}
	for(;j<=n;j++,k++)
	{
		x[k]=a[j];
	}
	for(j=0,i=m;j<k;j++,i++)
	{
		a[i]=x[j];
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
	mergesort(a,0,n);
	display(n,a);
}
