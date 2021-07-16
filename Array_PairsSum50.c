#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void pairs(int a[],int n)
{
	int i,j;
	printf("All the pairs of elements whose sum is 50:");
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i]+a[j])==50)
			{
				printf("\n%d %d",a[i],a[j]);
			}
		}
	}
}
void main()
{
	int a[MAX],n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	pairs(a,n);
}
