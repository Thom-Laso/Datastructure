#include<stdio.h>
 #include<stdlib.h> 
struct node 
{  
	int data;  
	struct node* left;  
	struct node* right;
 };
 struct node* root=NULL;
 void insertElement(int); 
void inorderTraversal(struct node*); 
struct node* findSmallestElement(struct node*); 
struct node* findLargestElement(struct node*); 
int main() 
{  
	int option, val;  
	struct node* ptr;  
	do  
	{   
		printf("\n******MAIN MENU******\n");   
		printf("1.Insert Element\n");   
		printf("2.Inorder Traversal\n");   
		printf("3.Find the smallest element\n");     
		printf("4.Find the largest element\n");   
		printf("5.Press 5 to exit\n");   
		printf("\nEnter your option: ");   
		scanf("%d",&option);   
		switch(option)     
		   {    
			case 1:printf("\nEnter value of the new node:");                
			scanf("%d",&val);
		                  insertElement(val);
				break;               
			case 2:printf("\nThe elements of the tree in inorder traversal are:\n");                
			inorderTraversal(root);                
				break;                      
			case 3:ptr=findSmallestElement(root);                                                        
			printf("\nThe smallest element in the binary search tree = %d",ptr->data);                
				break;                  
			case 4:ptr=findLargestElement(root); 
                                             	printf("\nThe largest element in the binary search tree = %d",ptr->data);                                
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
 
struct node* findSmallestElement(struct node* tree) 
{  
	if(tree==NULL || tree->left==NULL)     
		return tree;  
	else     
		return findSmallestElement(tree->left);    
}
  
struct node* findLargestElement(struct node* tree) 
{  
	if(tree==NULL || tree->right==NULL)     
		return tree;  
	else     
		return findLargestElement(tree->right);    
} 