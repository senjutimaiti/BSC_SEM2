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
void push(BST *stack[],int *top, BST *node)
{
	if(*top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		stack[++*top] = node;
	}
}
BST* pop(BST *stack[],int *top)
{
	return stack[*top--];
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
void inorder2(BST *root) 
{ 
  BST *p = root; 
  BST *stk[5];
  int top=-1;
  int i= 1; 
  while (i) 
  { 
    if(p!=NULL) 
    { 
      push(stk, &top, p);                                                
      p = p->left;   
    }       
    else                                                              
    { 
      if (top!=-1) 
      { 
        p = stk[top];
        top--;
        printf("%d ", p->data); 
  	    p=p->right; 
      } 
      else
        i=0;  
    } 
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
void preorder2(BST *root) 
{ 
  BST *p = root; 
  BST *stk[5];
  int top=0;
  int i= 1; 
  while (i<=5) 
  { 
    if(p!=NULL) 
    { 
    	printf("%d ", p->data);
      	push(stk, &top, p);                                                
      	p = p->left;   
    }       
    else                                                              
    { 
      if (top!=0) 
      { 
        p = stk[top];
        top--;
        //printf("%d ", p->data); 
  	    p=p->right; 
      } 
      else
        i++;  
    } 
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
		printf("Display in:\n1) Inorder\n2) Postorder\n3) Preorder\n4) Inorder\n5) Postorder\n6) Preorder\n");
		fflush(stdin);
		getchar();
		scanf("%d", &n);
		switch(n)
		{
			case 1: inorder(root);break;
			case 2: postorder(root);break;
			case 3: preorder(root);break;
			case 4: inorder2(root);break;
			//case 5: postorder2(root);break;
			case 6: preorder2(root);break;
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

