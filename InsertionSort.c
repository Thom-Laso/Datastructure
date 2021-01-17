/*  Sorting an array using Insertion Sort Algorithm  */ 
#include<stdio.h> 
void insertion_sort(int arr[],int n);

main() 
{    
	int arr[10],i,n;   
	printf("Enter the size of the array= ");      
	scanf("%d",&n);      
	for(i=1; i<=n; i++)      
	{       
		printf("Enter the value for a[%d]=", i);       scanf("%d",&arr[i]);   
	}       
	printf("The un-sorted array is:\n");    
	for(i=1; i<=n; i++)    
	printf ( "%4d\t", arr[i] );    
	insertion_sort(arr,n);       
	printf("\nThe sorted array is: \n");    
	for(i=1; i<=n; i++)    
	printf ( "%4d\t", arr[i] ) ;    
	return 0; 
}

void insertion_sort(int arr[],int n) /*  Algorithm for insertion sort */ 
{  
	int i,j,key;  
	for(j=2;j<=n;j++)  
	{   
		key=arr[j];   
		i=j-1;   
		while(i>0 && arr[i]>key)     
		{      
			arr[i+1]=arr[i];    
			i--;           
		}        
		arr[i+1]=key;	  
	} 
}  