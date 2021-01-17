//pass by reference/address

# include<stdio.h>
# include<stdlib.h>

void swap();
int main()
{
	int a = 5, b = 6;
	printf("Before Swapping ->> a=%d b=%d\n",a, b);
	swap(&a, &b);
	printf("After Swapping->> a=%d =%d\n",a, b);
}

void swap(int *x, int *y)
{
	int f;
	f = *x;
	*x = *y;
	*y = f;
	printf("\n\nIn function Swap ->> *x =%d   *y = %d\n",*x, *y);
}