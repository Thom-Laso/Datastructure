#include<stdio.h> 
void swap(int a[],int,int); 
void quick_sort(int a[],int lb, int ub); 
int partition(int a[],int lb, int ub); 
main() 
{  
	int arr[10],i,n;   
	printf("Enter the size of the array= ");
	scanf("%d",&n);      
	for(i=0; i<n; i++)        
	{       
		printf("Enter the value for a[%d]=", i);       
		scanf("%d",&arr[i]);     
	}     
	printf("The un-sorted array is:\n");    
	for(i=0; i<n; i++)    
	printf ( "%4d\t", arr[i] );    
	quick_sort(arr,0,n-1);    
	printf("\nThe sorted array using quick sort algorithm is: \n");    
	for(i=0; i<n; i++)    
		printf ( "%4d\t", arr[i] ) ;    
	return 0;  
} 
void quick_sort(int a[],int lb, int ub) 
{  
	int loc;     
	if(lb<ub)     
	{      
		loc=partition(a,lb,ub);      
		quick_sort(a,lb,loc-1);      
		quick_sort(a,loc+1,ub);  
	} 
}  
int partition(int a[],int lb, int ub) 
{  
	int pivot=a[lb],start=lb,end=ub;  
	while(start<end)  
	{   
		while(a[start]<=pivot)   
		{    
			start++; 
  		}   
  		while(a[end]>pivot)   
  		{    
  			end--;   
  		}   
  		if(start<end)   
  		{    
  			swap(a,start,end);   
  		}  
  	}  
  	swap(a,lb,end);  
  	return end; 
}  
void swap(int a[],int x,int y) 
{  
	int temp;  
	temp=a[x];  
	a[x]=a[y];  
	a[y]=temp; 
}    
    