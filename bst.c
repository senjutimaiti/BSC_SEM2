#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node BST;
BST* getnode()
{
	BST *newnode;
	newnode = (BST*)malloc(sizeof(BST));
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}
BST* Create_BST(BST* root,int key)
{
	char ch;
	if(root==NULL)
	{
		root=getnode();
		root->data=key;
	}
	else
	{
		if(root->data>key)
		{
			root->left=Create_BST(root->left,key);
		}
		else if(root->data<key)
		{
			root->right=Create_BST(root->right,key);
		}
		else
		{ 
			printf("Invalid Key value");
		}
	}
	return(root);
}
void inorder(BST* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(BST* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void preorder(BST* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	int n,f;
	BST *root=NULL;
	while(1)
	{
		printf("Enter a number ");
		fflush(stdin);
		getchar();
		scanf("%d", &n);
		root=Create_BST(root,n);
		printf("\nDo you want to enter again? Press 1 to continue.");
		fflush(stdin);
		getchar();
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}
	}
	while(1)
	{
		printf("Display in:\n1) Inorder\n2) Postorder\n3) Preorder\n");
		fflush(stdin);
		getchar();
		scanf("%d", &n);
		switch(n)
		{
			case 1: inorder(root);break;
			case 2: postorder(root);break;
			case 3: preorder(root);break;
			default: printf("Invalid choice");
		}
		printf("\nDo you want to display again? Press 1 to continue.");
		fflush(stdin);
		getchar();
		scanf("%d", &f);
		if(f!=1)
		{
			break;
		}
	}
	return 0;
}

