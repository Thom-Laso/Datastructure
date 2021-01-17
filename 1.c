#include<stdio.h>
 #include<stdlib.h>
 struct node 
	{  int data;
	  struct node* left;
	  struct node* right;
	 };
 struct node* root=NULL;; 
void insertElement(int);
 void inorderTraversal(struct node*);
 void preorderTraversal(struct node*);
 void postorderTraversal(struct node*);
 int main()
 {
	  int option, val;
	  do
	  {
		   printf("\n\n******MAIN MENU******\n");
		   printf("1.Insert Element\n");
		   printf("2.Inorder Traversal\n");
		   printf("3.Preorder Traversal\n");
		   printf("4.Postorder Traversal\n");
		   printf("5.Press 5 to exit\n");
		   printf("\n\n Enter your option: ");
		   scanf("%d",&option);
		   switch(option)
		   {
			case 1:printf("\nEnter value of the new node:");           						scanf("%d",&val);
			insertElement(val);
			           break;
		                case 2:printf("\nThe elements of the tree in inorder traversal are:\n");
			           inorderTraversal(root);
				           break; 
		              case 3:printf("\nThe elements of the tree in preorder traversal are:\n"); 
			          preorderTraversal(root); 
			          break;  
		             case 4:printf("\nThe elements of the tree in postorder traversal are:\n"); 
        			        postorderTraversal(root); 
			          break;
	           }
	  } while(option!=5);
	  return 0;
 } 
 void insertElement(int val)
 {
	  struct node* t,*parent,*curr;
	  t=(struct node*)malloc(sizeof(struct node));
	  t->data=val;
	  t->left=NULL;
	  t->right=NULL;
	  parent=root;
	  if(root==NULL)
	  {
	   	root=t;
	  }
	  else
	  {
	                curr=root;
	                while(curr)
		{
			    parent=curr;    
			    if(t->data>curr->data)    
			    {     
				curr=curr->right;
			    }
			    else
			    {     
				curr=curr->left;
			    }
		 }   
		if(t->data>parent->data)
   		{
    			parent->right=t;   
		}   
		else   
		parent->left=t;  
	}
 } 

void inorderTraversal(struct node* tree) 
{     
	if(tree!=NULL)    
	{        
		inorderTraversal(tree->left);        
		printf("%d ",tree->data);        
		inorderTraversal(tree->right);    
		} 
} 

void preorderTraversal(struct node* tree)  
{   
	if(tree!=NULL)    
	{        
		printf("%d ",tree->data);        
		preorderTraversal(tree->left);        
		preorderTraversal(tree->right);    
	} 
}

void postorderTraversal(struct node* tree)  
{   
	if(tree!=NULL)    
	{        
		postorderTraversal(tree->left);        
		postorderTraversal(tree->right);        
		printf("%d ",tree->data);    
	}    
} 