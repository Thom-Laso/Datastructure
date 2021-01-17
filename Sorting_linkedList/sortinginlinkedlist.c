#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* link;
};
struct node* root=NULL;
int len;
void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void sort(void);
void main()
{
int ch;
do {
printf("Sorted List Operations:\n");
printf("1.Append\n");
printf("2.Addatbegin\n");
printf("3.Addatafter\n");
printf("4.Length\n");
printf("5.Display\n");
printf("6.Quit\n");
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
case 6:exit(1);
break;
default: printf("Invalid choice\n\n");
}
 } while(ch!=0);
}

void append()
{
struct node* temp,*p;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->link=NULL;//list is empty
if(root==NULL)
{
root=temp;
}
else
{
 //struct node* p;
 p=root;
 while(p->link!=NULL)
 {
 p=p->link;
 }
 p->link=temp;
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
temp=temp->link;
}
return count;
}
void display()
{
struct node* temp;
temp=root;
sort();
if(temp==NULL)
{
 printf("List is empty.\n\n");
}
else
{
while(temp!=NULL)
{
printf("%d-->",temp->data);
temp=temp->link;
}
printf("\n\n");
}
}
void addatbegin(void)
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{
root=temp;
}
else
{
temp->link=root;// first right connection
root=temp;// finally left connection
}
}
void addatafter(void)
{
struct node* temp,*p;
int loc,len,i=1;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter location:");
scanf("%d",&loc);
len=length();
if(loc>len)
 {
printf("Invalid location\n");
printf("Currently list is having %d nodes\n",len);
 }
 else
 {
 p=root;
 while(i<loc)
 {
 p=p->link;
 i++;
 }
 //temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter node data:");
 scanf("%d",&temp->data);
 temp->link=NULL;
 temp->link=p->link;// first right connection
 p->link=temp;// finally left connection
 }
}
void sort()
{ 
 int temp;
 struct node* i,*j;
 for(i=root;i->link!=NULL;i=i->link)
 {
 	for(j=i->link;j!=NULL;j=j->link)
	 {
	 if(i->data>j->data)
		 {
			 temp=i->data;
			 i->data=j->data;
			 j->data=temp;
		 }
	}
 }
}