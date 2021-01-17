#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* left;
 struct node* right;
};
struct node* root=NULL;
int len;
void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void delete(void);
void main()
{
int ch;
while(1)
{
printf("Double Linked List Operations:\n");
printf("1.Append\n");
printf("2.Addatbegin\n");
printf("3.Addatafter\n");
printf("4.Length\n");
printf("5.Display\n");
printf("6.Delete\n");
printf("7.Quit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:append();
break;
case 2:addatbegin();
break;
case 3:addatafter();
break ;
case 4:len=length();
printf("Length=%d\n",len);
break;
case 5:display();
break;
case 6:delete();
break;
case 7:exit(1);
break;
default: printf("Invalid choice\n\n");
}
}
}
void append()
{
struct node* temp,*p;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->left=NULL;//list is empty
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
 //struct node* p;
 p=root;
 while(p->right!=NULL)
 {
 p=p->right;
 }
 p->right=temp;
 temp->left=p;
}
}
void addatbegin(void)
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
temp->right=root;
root->left=temp;
root=temp;
}
}
int length()
{
int count=0;
struct node* temp;
temp=root;
while(temp!=NULL)
{
count++;
temp=temp->right;
}
return count;
}
void display()
{
struct node* temp;
temp=root;
if(temp==NULL) 
{
 printf("List is empty.\n\n");
}
else
{
while(temp!=NULL)
{
printf("%d-->",temp->data);
temp=temp->right;
}
printf("\n\n");
}
}
void addatafter(void)
{
struct node* temp,*p;
int loc,len,i=1;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter location to add:");
scanf("%d",&loc);
len=length();
if(loc>len)
 {
printf("Invalid location\n");
printf("Currently list is having %d nodes\n",len);
 }
 else
 {
 //temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter node data:");
 scanf("%d",&temp->data);
 temp->left=NULL;
 temp->right=NULL;
 p=root;
 while(i<loc)
 {
 p=p->right;
 i++;
 }
 temp->right=p->right;
 p->right->left=temp;
 temp->left=p;
 p->right=temp;
 }
}
void delete(void)
{
struct node* temp,*p,*q;
int loc,len,i=1;
//temp=(struct node*)malloc(sizeof(struct node));
printf("Enter location to delete:");
scanf("%d",&loc);
len=length();
if(loc>len)
 {
printf("Invalid location\n");
 }
 else if(loc==1)
 {
 temp=root;
 root=temp->right;
 temp->right=NULL;
 free(temp);
 }
else
 {
p=root;
while(i<loc-1)
 {
 p=p->right;
 i++;
 }
q=p->right;
p->right=q->right;
q->right=NULL;
q->left=NULL;
free(q);
 }
}