#include <stdio.h>
#include <stdlib.h>
void display(int n, int a[n])
{
	int i,j;
	for(i=0;i<n;i++)
	printf("%d\t", a[i]);
	printf("\n");
}
void bubsort(int n, int *k)
{
	int a[n];
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		a[i]=*k;
		k++;
	}
	for(i=0;i<n-1;i++)
	{
		printf("Pass %d\n", (i+1));
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		display(n,a);	
	}
	printf("Sorted array\n");
	display(n,a);
}
void controlled_bubsort(int n, int *k)
{
	int a[n];
	int i,j,flag=1,p=1;
	for(i=0;i<n;i++)
	{
		a[i]=*k;
		k++;
	}
	for(i=n-1;i>0 && flag==1 ;i--)
	{
		printf("Pass %d\n", (p++));
		for(j=0,flag=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
				flag=1;
			}
		}
		if(flag==1)
				display(n,a);	
	}
	printf("Sorted array\n");
	display(n,a);
}
void selsort_min(int n, int *k)
{
	int i,j,min;
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=*k;
		k++;
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		if(min!=i)
		{
			a[i]=a[min]+a[i];
			a[min]=a[i]-a[min];
			a[i]=a[i]-a[min];
		}
		printf("Pass %d\n",(i+1));
		display(n,a);
	}
	printf("Sorted array\n");
	display(n,a);
}
void selsort_max(int n, int *k)
{
	int i,j,max;
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=*k;
		k++;
	}
	for(i=n-1;i>0;i--)
	{
		max=0;
		for(j=1;j<=i;j++)
		{
			if(a[j]>a[max])
			max=j;
		}
		if(max!=i)
		{
			a[i]=a[max]+a[i];
			a[max]=a[i]-a[max];
			a[i]=a[i]-a[max];
		}
		printf("Pass %d\n",(n-i));
		display(n,a);
	}
	printf("Sorted array\n");
	display(n,a);
}
void insertion(int n, int *k)
{
	int i,j,temp;
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=*k;
		k++;
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1; j>=0; j--)
		{
			if(temp<a[j])
				a[j+1]=a[j];
			else
				break;
		}
		if(j!=(i-1))
			a[j+1]=temp;
		printf("Pass %d\n",i);
		display(n,a);
	}
	printf("Sorted array\n");
	display(n,a);
}
void quicksort(int a[],int m,int n, int k)
{
	int i,j,piv;
	if(m<n)
	{
		piv=a[m];
		i=m+1;
		j=n;
		while(i<=j)
		{
			while(i<=n && a[i]<= piv)
				i++;
			while(j>m && a[j]>= piv)
				j--;
			if(i<j)
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
		if(m!=j)
		{
			a[m]=a[m]+a[j];
			a[j]=a[m]-a[j];
			a[m]=a[m]-a[j];
		}
		quicksort(a,m,j-1,k);
		quicksort(a,j+1,n,k);
	}
	printf("\n");
	display(k,a);	
}
main()
{
	int n,i,f,num;
	printf("Enter the number of elements ");
	scanf("%d", &n);
	if(n>0)
	{
		int a[n];
		printf("Enter the elements ");
		for(i=0;i<n;i++)
		scanf("%d", &a[i]);	
		do
		{
			printf("\nEnter:\n1 bubble sort\n2 controlled bubble sort\n3 selsort_min\n4 selsort_max\n5 insertion sort\n6 quick sort\n");
			scanf("%d", &num);
			switch(num)
			{
				case 1: bubsort(n,a);
				break;
				case 2: controlled_bubsort(n,a);
				break;
				case 3: selsort_min(n,a);
				break;
				case 4: selsort_max(n,a);
				break;
				case 5: insertion(n,a);
				break;
				case 6: quicksort(a,0,n,n);
				break;
				default: printf("Wrong Choice");
			}
			printf("\nEnter 1 to continue ");
			scanf("%d", &f);
		}
		while(f==1);
	}
	else
	printf("Wrong Input");
}
