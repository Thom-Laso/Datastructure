//program to pass base address of an array to a function
#include<stdio.h>
void modify(int[]);
main()
{
	int i, a[]={10,20,30,40,50};
	modify(a);
	printf("Modified elements are as follows:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
}

void modify(int x[ ])
{
	int i;
	for(i=0; i<5; i++)
	{
		x[i]=x[i]+5;
	}
}