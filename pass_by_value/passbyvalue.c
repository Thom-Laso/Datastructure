//pass by value

#include<stdio.h>
#include<stdlib.h>

void swap();
int main()
{
	int a, b;
	a = 5;
	b = 6;
	printf("Before Swapping ->> a=%d b=%d\n\n",a, b);
	swap(a,b);
	printf("\nAfter Swapping\n");
	printf("a=%d b=%d\n",a, b);
}


void swap(int x, int y)
{

	int f;
	f = x;
	x = y;
	y = f;
	printf("x=%d y=%d",x, y);
}
