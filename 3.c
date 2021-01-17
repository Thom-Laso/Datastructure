#include<stdio.h> 
#include<stdlib.h> 
struct node 
{  
	int data;  
	struct node* left;  struct node* right; 
}; 
struct node* root=NULL; 
void insertElement(int); 
void inorder(struct node*); 
struct node* delete_node(struct node*,int); 
struct node* minValueNode(struct node*); 
int main() 
{
	  int option, val, del_ele;  
	do  
	{   
		printf("\n******MAIN MENU******\n");
		printf("1.Insert Element\n");   
		printf("2.Inorder Traversal\n");   
		printf("3.Delete an Element\n");   
		printf("4.Press 4 to exit\n");   
		printf("\nEnter your option: ");   
		scanf("%d",&option);   
		switch(option)     
		{    
			case 1:printf("\nEnter value of the new node:");           
				scanf("%d",&val);              
			insertElement(val);           
				break;               
			case 2:printf("\nInorder traversal of BST:");                    
			inorder(root);           
				break;                  
			case 3:printf("\nEnter the node to be deleted: ");                    
				scanf("%d",&del_ele);                    
			delete_node(root,del_ele);        
			printf("\nInorder traversal after deletion:");                    
			inorder(root);        
				break;       
    		}  
	} while(option!=4);  
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
  
void inorder(struct node* root) 
 {   
	if(root!=NULL)   
	{     
		inorder(root->left);    
		printf("%d ",root->data);    
		inorder(root->right);  
	}  
}    

//function to delete the given node 
struct node* delete_node(struct node* root,int data)  
{   
	if(root==NULL)   
	return root; 
//if key to be deleted is smaller than root's key 
if (data<root->data) 
root->left=delete_node(root->left,data); 
//if key to be deleted is greater than root's key  
else if(data>root->data)  
root->right=delete_node(root->right,data);  
else  
{   
	//node with only one child or no child   
	if (root->left==NULL)   
	{      
		struct node *temp=root->right;      
		free(root);      
		return temp;  
	}   
	else if (root->right==NULL)   
	{      
		struct node *temp=root->left;      
		free(root);      
		return temp;   
	}   
	else   
	{  
	 //node with two children   
	 struct node* temp=minValueNode(root->right);   
	//copy the inorder successor content to this node   
	root->data=temp->data;   
	//delete the inorder successor 
  	root->right=delete_node(root->right,temp->data);       
	}  
}   
return root;  
}    
//function to find the minimum value node 
struct node* minValueNode(struct node*node)     
{      
	struct node* current=node;      
	//loop down to find the leftmost leaf      
	while(current->left!=NULL)      
	current=current->left;   
	return current;  
}   