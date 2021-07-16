#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int count;
struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node TREE;

TREE *getnode()
{
	TREE *newnode;
	newnode=(TREE *)malloc(sizeof(TREE));
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

void push(TREE *stack[],int *top, TREE *node)
{
	if(*top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		stack[++*top] = node;
	}
}
/*TREE* pop(TREE *stack[],int *top)
{
	return stack[*top--];
}*/
TREE *create_bt(TREE *root)
{
	TREE *stk[MAX],*head;
	int top = 0,flag;
	char choice, link;
	do{
		if(root==NULL){
			root = getnode();
			if(top==0){
				stk[top] = root;
			}
			printf("Enter data\n");
			scanf("%d",&root->data);
			count++;
			if(top>0&&link=='l'){
				stk[top]->left = root;
			}
			else if(top>0&&link=='r'){
				stk[top]->right = root;
				top--;
			}
			flag = 0;
		}
		if(flag==0){
			printf("Current node value: %d\n",root->data);
			printf("left child?\n");
			fflush(stdin);
			getchar();
			scanf("%c", &choice);
		}
		else{
			choice = 'n';
		}
		if(choice=='y'){
			push(stk,&top,root);
			root = root->left;
			link = 'l';
		}
		else{
			printf("Current node value: %d\n",root->data);
			printf("right child?\n");
			fflush(stdin);//;.lp[;]
			getchar();
			scanf("%c", &choice);
			if(choice=='y'){
				if(stk[top]!=root||top==0){
					push(stk,&top,root);
				}
				root = root->right;
				link = 'r';
			}
			else{
				if(top!=-1){
					root = stk[top];
					top--;
				}
				flag = 1;
			}
		}
	}while(top!=-1);
	return(stk[0]);
}
void inorder1(TREE *root)
{
	if(root!=NULL)
	{
		inorder1(root->left);
		printf(" %d ",root->data);
		inorder1(root->right);
	}
}
void inorder2(TREE *root) 
{ 
  TREE *p = root; 
  TREE *stk[MAX];
  int top=0;
  int i= 1; 
  while (i<=count) 
  { 
    if(p!=NULL) 
    { 
      push(stk, &top, p);                                                
      p = p->left;   
    }       
    else                                                              
    { 
      if (top!=0) 
      { 
        p = stk[top];
        top--;
        printf("%d ", p->data); 
  	    p=p->right; 
      } 
      else
        i++;  
    } 
  } 
}   
int main()
{
	TREE *root=NULL;
	root=create_bt(root);
	inorder1(root);
	printf("\n");
	inorder2(root);
	printf("\n");
	return 0;
}
