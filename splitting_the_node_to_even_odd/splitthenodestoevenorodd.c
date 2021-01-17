#include<stdio.h>
#include<stdlib.h>
typedef struct node
	{
		int data;
		struct node *next;  
	}node;
node *A=NULL;
node *B=NULL;
node *C=NULL;
node *D=NULL;
int add_node(node **q,int n)
{
	node *temp,*r;
	if(*q==NULL)
	{
		temp=(node*)malloc(sizeof(struct node));
		temp->data=n;
		temp->next=NULL;
		*q=temp;
	}
	else
	{
		temp=*q;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			r=(node*)malloc(sizeof(struct node));
			r->data=n;
			r->next=NULL;
			temp->next=r;
		}
		return 0;
}

int display(node *q)
{
	if(q==NULL)
	{
		printf("Linked Listed is Empty\n");
		return 0;
	}
	while(q != NULL)
	{
		printf("\t%d->",q->data);
		q=q->next;
	}printf("\t NULL");
	return(0);
}

int splitintoevenorodd(node *q,int iii)
{
	while(q != NULL)
	{
		 if(iii % 2 != 0)
			add_node(&A, q->data);
		q=q->next;
		if(q==NULL)
		return(0);
		if(iii % 2 == 0)
			add_node(&B, q->data);
		q=q->next;
	}
	return 0;
}
int main()
{
	node *p;
	p=NULL;
	int n,choice,i;
	char ch;
a:
printf("\n1.Insert a node to a Linked List.\n 2.Display Linked List.\n 3.Split the Linked list.\n 4.Exit\nEnter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	printf("Add note to the linked list\n");
	z:
	printf("Enter the number of elemets:");
	scanf("%d",&n);
	if(n<4)
	{
		printf("\nNumber of elements cannot be less then 4:");
		goto z;
	}for(i=1;i<=n;i++)
	{
		add_node(&p,i);
	}
	break;
	case 2:
	printf("The lined List is\n");
	display(p);
	break;
	case 3:
	printf("Spliting into 2 nodes-Even or Odd-:\n");
	splitintoevenorodd(p,n);
	printf("1st list of Odd:");
	display(A);
	printf("\n");
	printf("2nd List of Even:");
	display(B);
	break;
	default:
	printf("wrong input");
}
printf("\n\nTo continue press Y/y:\n\n");
scanf("%s",&ch);
if(ch=='Y' || ch=='y')

goto a;
return(0);
}