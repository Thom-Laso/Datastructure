# include<stdio.h>
# include<stdlib.h>

struct node
{
	int data;
	struct node*n;
};

struct node* root = NULL;
void append(void);
void display(void);
void addatbegin(void);

int main()
{
	int ch;
	while(1)
	{
			printf("Single Listed Operation:\n");
	printf("1.Append\n");
	printf("2.Display\n");
	printf("3.Add at Begin\n");
	printf("4.Quit\n");
	printf("Enter Your Choice:");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1: append();
		break;

		case 2: display();
		break;

		case 3: addatbegin();
		break;

		case 4: exit(1);
		default: printf("Invalid Choice\n");	
		}
	}

}

void append()
{
	struct node* temp, *p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node number:\n");
	scanf("%d",&temp->data);
	temp->n=NULL;
	if(root == NULL)
	{
		
		root=temp;		
	}
	else
	{
		p=root;
		while(p->n != NULL)
		{
			p = p->n;
		}
		p->n=temp;
	}
}

void display()
{
	struct node* temp;
	temp = root;
	if(temp == NULL)
	{
		printf("List is Empty\n");
	}
	while(temp!= NULL)
	{
		printf("%d-->>",temp->data);
		temp=temp->n;
	}
	printf("\n\n");
}

void addatbegin()
{
	struct node* temp, *p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data:\n");
	scanf("%d",&temp->data);
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		temp->n = root;
		root = temp;
	}
}