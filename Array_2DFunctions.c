#include <stdio.h>
void addition(int m,int n, int a[m][n],int b[m][n])
{
	printf("The sum\n");
	int c[m][n];
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}
void multiply(int m,int n,int m1, int n1, int a[m][n],int b[m1][n1])
{
	printf("The product\n");
	int c[m][n1];
	int i,j,h,sum=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n1;j++)
		{
			for(h=0;h<m1;h++)
			{
				sum=sum+a[i][h]*b[h][j];
			}
			c[i][j]=sum;
			sum=0;
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}
transpose(int m,int n,int a[m][n])
{
	printf("Transpose of the array\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}
}
principlediagonal(int m,int n,int a[m][n])
{
	if(m==n)
	{
		printf("Principle diagonal");
		printf("\n");
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				printf("%d\t", a[i][j]);
				else
				printf("\t");
			}
			printf("\n");
		}
	}
	else
	printf("diagonals don't exist");
}
npdiagonal(int m,int n,int a[m][n])
{
	if(m==n)
	{
		printf("Non-Principle diagonal\n");
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if((i+j)==(m-1))
				printf("%d\t", a[i][j]);
				else
				printf("\t");
			}
			printf("\n");
		}
	}
	else
	printf("diagonals don't exist");
}
boundary(int m,int n,int a[m][n])
{
	printf("boundary elements of the array\n");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0||j==0||i==(m-1)||j==(n-1))
			printf("%d\t", a[i][j]);
			else
			printf("\t");
		}
		printf("\n");
	}
}
main()
{
	int m,n,m1,n1,i,j,f=1;
	printf("Enter the order of the array ");
	scanf("%d", &m);
	scanf("%d", &n);
	if(m>0 && n>0)
	{
		int a[m][n];
		printf("Enter the elements of the array ");
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d", &a[i][j]);
		printf("\nthe array\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d\t", a[i][j]);
			printf("\n");
		}
		while(f==1)
		{
			int num;
			printf("Enter your choice:\n1. Transpose\n2. Principle diagonal\n3. Nom-Principle diagonal\n4. boundary elements\n5. Addition\n6. Multiplication\n");
			scanf("%d", &num);
			switch(num)
			{
				case 1:transpose(m,n,a);
					break;
				case 2:principlediagonal(m,n,a);
					break;
				case 3:npdiagonal(m,n,a);
					break;
				case 4:boundary(m,n,a);
					break;
				case 5:
					{
						int b[m1][n1];
						printf("Enter the order of the second array ");
						scanf("%d", &m1);
						scanf("%d", &n1);
						if (m1>0 && n1>0)
						{
							int b[m1][n1];
							printf("Enter the elements of second array ");
							for(i=0;i<m1;i++)
								for(j=0;j<n1;j++)
									scanf("%d", &b[i][j]);
							if(m1==m && n1==n)
								addition(m,n,a,b);
							else
								printf("addition isn't possible\n");
						}
						else
							printf("Wrong Input");
					}
					break;
					case 6:
					{
						int b[m1][n1];
						printf("Enter the order of the second array ");
						scanf("%d", &m1);
						scanf("%d", &n1);
						if (m1>0 && n1>0)
						{
							int b[m1][n1];
							printf("Enter the elements of second array ");
							for(i=0;i<m1;i++)
								for(j=0;j<n1;j++)
									scanf("%d", &b[i][j]);
							if(n==m1)
								multiply(m,n,m1,n1,a,b);
							else
								printf("multiplication isn't possible\n");
						}
						else
							printf("Wrong Input");
					}
					break;
				default: printf("Wrong choice");
			}
			printf("\nEnter 1 to continue or any other digit to exit");
			scanf("%d", &f);
		}
	}
	else
	printf("Wrong Input");
}
