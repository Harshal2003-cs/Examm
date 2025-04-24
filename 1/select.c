#include <stdio.h> 
#include<time.h>
#include<stdlib.h>
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionsort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		if(min_idx != i) 
			swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int i,n;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of an array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	clock_t start,end;
	selectionsort(arr,n);
	start=clock();
// time to sort elements
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Sorted elements are\n");
	printArray(arr,n);
	printf("Time taken for the sort to elements of an array %f\n",time_taken);
	return 0;
	


} 

