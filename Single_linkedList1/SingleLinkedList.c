#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
};
struct node * root = NULL;
int len;
void append(void);
void display(void);
void add_at_begin(void);
int length(void);
//void add_at_after(void);
//void sort(void);

int main()
{
	int ch;
	while(1)
	{
		printf("\n---Single Linked List---\n");
		printf("1. Append\n");
		printf("2. Display\n");
		printf("3. Quit\n");
		printf("4. Add At Begin\n");
		printf("5. Count\n");
//		printf("6. Add At After\n");
//		printf("7. Sort\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: append();
			break;

			case 2: display();
			break;

			case 3: exit(1);

			case 4: add_at_begin();
			break;

			case 5: len=length();
				   printf("The length of the Linked List is %d",len);
			break;

//			case 6: add_at_after();
//			break;

//			case 7: sort();
//			break;
		}
	}
}

void append()
{
	struct node *temp, *p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data\n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(root == NULL)	
	{
		root = temp;		
	}
	else
	{
		p=root;
		while(p->link != NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}

void display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
		printf("List is Empty\n");
	while(temp != NULL)
	{
		printf("%d->>",temp->data);
		temp=temp->link;
	}
}

void add_at_begin()
{
	struct node *new_temp,*p;
	new_temp = (struct node*)malloc(sizeof(struct node));
	p=root;
	root = new_temp;
	printf("Enter node data:\n");
	scanf("%d",&new_temp->data);
	new_temp->link=p;
}

int length()
{
	int count = 0;
	struct node *temp;
	temp=root;
	while(temp != NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
