/*sorting an array using Selection Sort Algorithm*/
#include<stdio.h>

main() 
{    
		int a[10],i,j,n,temp;   
		printf("Enter the size of the array= ");
	scanf("%d",&n);      
	for(i=0; i<n; i++)      
	{       
		printf("Enter the value for a[%d]=", i);       scanf("%d",&a[i]);   
	}    
		printf("The un-sorted array is:\n");    
		f or(i=0; i<n; i++)    
		printf ( "%4d\t", a[i]);  
	   /*sorting the values of the elements of the array*/   
  		for(i=0;i<n-1;i++)           
   	for(j=i+1; j<n; j++)             
   		if (a[i]>a[j])             
   		{              
	   		temp=a[i];              
	   		a[i]=a[j];              
	   		a[j]=temp;
	   	}       
	   	printf("\nThe sorted array is: \n");    
	   		for(i=0; i<n; i++)    
	   		printf ( "%4d\t", a[i] );    
	   		return 0;    
} 