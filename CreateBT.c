#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node TREE;
TREE* getnode()
{
	TREE *newnode;
	//newnode=malloc(sizeof(TREE));
	newnode = (TREE*)malloc(sizeof(TREE));
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}
TREE* Create_BT(TREE* root)
{
	char ch;
	if(root==NULL)
	{
		root=getnode();
		printf("Enter the value of node: ");
		fflush(stdin);
		//getchar();
		scanf("%d", &root->data);
	}
	printf("Current Node value: %d",root->data);
	printf("Do you have a left child?: ");
	fflush(stdin);
	getchar();
	scanf("%c", &ch);
	if(ch=='y')
	{
		root->left=Create_BT(root->left);
	} 
	printf("Current Node value: %d",root->data);
	printf("Do you have a right child?: ");
	fflush(stdin);
	getchar();
	scanf("%c", &ch);
	if(ch=='y')
	{
		root->right=Create_BT(root->right);
	} 
	return(root);
}
void inorder(TREE* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
int main()
{
	TREE *root=NULL;
	root=Create_BT(root);
	inorder(root);
	return 0;
}

