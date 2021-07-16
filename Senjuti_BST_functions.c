#include<stdio.h>
#include<malloc.h>
#define MAX 30
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
/*Recursive*/
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
/*Iterative*/
BST* insert(BST* root,int key)
{
	BST *start,*temp,*ptr=getnode();
	ptr->data=key;
	if(root==NULL)
		root=ptr;
	else
	{
		start=root;
		while(start!=NULL)
		{
			temp=start;
			if(start->data > key)
				start=start->left;
			else if(start->data < key)
				start=start->right;
		}
		if(key < temp->data)
			temp->left=ptr;
		else if(key > temp->data)
			temp->right=ptr;
	}
	return(root);
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
void inorder(BST* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
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
void postorder(BST* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void Inorder(BST *root) 
{ 
  BST *p=root,* stk[MAX]; 
  int top=-1,i=1;
  while (i) 
  { 
    if(p!=NULL) 
    { 
      stk[++top]=p;                                                
      p = p->left;   
    }       
    else                                                              
    { 
      if (top!=-1) 
      { 
        p=stk[top--];
        printf("%d ", p->data); 
  	    p=p->right; 
      } 
      else
        i=0;  
    } 
  } 
}
void Preorder(BST *root) 
{ 
  BST *p=root,* stk[MAX]; 
  int top=-1,i=1;
  stk[++top]=p;
  while(i) 
  { 
    if(top!=-1)
    {
    	p=stk[top--];
  		printf("%d ", p->data);
    	if(p->right!=NULL) 
    		stk[++top]=p->right;
    	if(p->left!=NULL)
    		stk[++top]=p->left;
	}
  	else
  		i=0;
  } 
}
void Postorder(BST *root) 
{ 
  BST *p=root,* stk[MAX],* stack[MAX]; 
  int top1=-1,top2=-1,i=1;
  stk[++top1]=p;
  while(i) 
  { 
    if(top1!=-1)
    {
    	p=stk[top1--];
    	stack[++top2]=p;
  		if(p->left!=NULL)
    		stk[++top1]=p->left;
    	if(p->right!=NULL) 
    		stk[++top1]=p->right;
	}
  	else
  		i=0;
  } 
  i=1;
  while(i)
  {
  	if(top2!=-1)
  	{
	  	p=stack[top2--];
  		printf("%d ", p->data);
	}
	else
		i=0;
  }
}
BST* Search(BST* root,int n)
{
	if(root==NULL||root->data==n)
		return root;
	if(root->data<n)
		return Search(root->right,n);
	else
		return Search(root->left,n);
}
int Height(BST *root)  
{ 
	int l,r;
   if (root==NULL)  
       return 0; 
   else 
   { 
    	l=Height(root->left); 
        r=Height(root->right); 
       if (l>r)  
        	return(l+1); 
       else 
	   		return(r+1); 
   } 
}
void printLevel(BST* root) 
{ 
    int i,h=Height(root);  
    for (i=1; i<=h; i++) 
    {
        printf("\nLevel %d: ",(i-1));
		Level(root, i); 
	}
} 
int Level(BST* root, int l) 
{ 
    if (root==NULL) 
        return; 
    if (l==1) 
        printf("%d ", root->data); 
    else if (l>1) 
    { 
        Level(root->left,l-1); 
        Level(root->right,l-1); 
    } 
} 
int countNonLeaf(BST* root)
{
	int l,r;
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return 0;
	else
	{
		l=countNonLeaf(root->left);
		r=countNonLeaf(root->right);
		return (1+l+r);
	}
}
int countLeaf(BST* root)
{
	int l,r;
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
	{
		l=countLeaf(root->left);
		r=countLeaf(root->right);
		return (l+r);
	}
}
BST* mirror(BST* root)  
{ 
  if (root==NULL)  
    return;   
  else 
  { 
    BST* temp; 
    mirror(root->left); 
    mirror(root->right); 
    temp=root->left; 
    root->left=root->right; 
    root->right=temp; 
  }
  return(root); 
} 
int main()
{
	int num,n,f=1;
	BST *root=NULL,*c;
	while(f)
	{
		printf("Enter choice:\n1)Insert a node\n2)Delete a node\n3)Search a node in BST\n4)Traversal of BST (recursive)\n5)Traversal of BST (iterative)\n");
		printf("6)Level by level traversal\n7)No. of non-leaf and leaf nodes\n8)Height of BST\n9)Mirror image of BST\n");
		scanf("%d", &num);
		switch(num)
		{
			case 1:{printf("Enter the value to be inserted ");
					scanf("%d", &n);
					root=Insert(root,n);
				break;
			}
			case 2:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{printf("Enter the value to be deleted ");
					scanf("%d", &n);
					root=Delete(root,n);}
				break;
			case 3:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{printf("Enter the value to be searched ");
					scanf("%d", &n);
					c=Search(root,n);
					if(c!=NULL)
						printf("Node found\n");
					else
						printf("Node not found\n");
				}break;
			case 4:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{printf("\nInorder: ");
					inorder(root);
					printf("\nPreorder: ");
					preorder(root);
					printf("\nPostorder: ");
					postorder(root);
				}break;
			case 5:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{printf("\nInorder: ");
					Inorder(root);
					printf("\nPreorder: ");
					Preorder(root);
					printf("\nPostorder: ");
					Postorder(root);
				}break;
			case 6:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{printf("Levels of the tree:");
					printLevel(root);
				}break;
			case 7:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{n=countNonLeaf(root);
					printf("No. of non leaf nodes of the tree: %d\n",n);
					n=countLeaf(root);
					printf("No. of leaf nodes of the tree: %d\n",n);
				}break;
			case 8:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{n=Height(root);
					printf("Height of the tree: %d\n",n);
				}break;
			case 9:if(root==NULL)
						printf("BST doesn't exist\n");
					else
					{root=mirror(root);
					printf("After converting to its mirrored form\n");
					inorder(root);
					root=mirror(root);
				}break;
			default: printf("Wrong choice\n");
		}
		printf("\nDo you want to continue?(1 or 0) ");
		scanf("%d", &f);	
	}
}

