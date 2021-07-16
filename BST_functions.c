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
BST* Insert(BST* root,int key)
{
	if(root==NULL)
	{
		root=getnode();
		root->data=key;
	}
	else
	{
		if(root->data>key)
			root->left=Insert(root->left,key);
		else if(root->data<key)
			root->right=Insert(root->right,key);
	}
	return(root);
}
void Inorder(BST* root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d ",root->data);
		Inorder(root->right);
	}
}
BST* Delete(BST* root,int key)
{
	if(root==NULL)
	{
		printf("Node not found\n");
		return root;
	}
	if(root->data>key)
		root->left=Delete(root->left,key);
	else if(root->data<key)
		root->right=Delete(root->right,key);
	else
	{
		BST *p;
		if(root->right==NULL)
			return(root->left);
		else if(root->left==NULL)
			return(root->right);
		p=root->right;
		while(p->left!=NULL)
			p=p->left;
		root->data=p->data;
		root->right=Delete(root->right,p->data);
	}
	return(root);
}
int main()
{
	int num,n,f;
	BST *root=NULL;
	while(1)
	{
		printf("Enter choice:\n1)Insert a node\n2)Delete a node\n3)Traverse BST\n");
		fflush(stdin);
		scanf("%d", &num);
		switch(num)
		{
			case 1:{printf("Enter the value to be inserted ");
					fflush(stdin);
					scanf("%d", &n);
					root=Insert(root,n);
				break;
			}
			case 2:{printf("Enter the value to be deleted ");
					fflush(stdin);
					scanf("%d", &n);
					root=Delete(root,n);
				break;
			}
			case 3: Inorder(root);
				break;
			default: printf("Wrong choice\n");
		}
		printf("\nDo you want to continue?(1 or 0) ");
		fflush(stdin);
		scanf("%d", &f);
		if(f!=1)
			break;	
	}
}

