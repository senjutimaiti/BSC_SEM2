#include<stdio.h>
#include<math.h>
void main()
{
	int a[7];
	int n,f,in,i;
	printf("Enter the root: ");
	scanf("%d", &a[1]);
	printf("Enter the nodes: ");
	for(i=2;i<=7;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("The tree: ");
	for(i=1;i<=7;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n1)Parent\n2)children\nEnter your choice: ");
	scanf("%d", &n);
	printf("Enter index ");
	scanf("%d", &n);
}
