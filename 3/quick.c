 #include <stdio.h> 
#include<time.h>
#include<stdlib.h>
void swap(int *p1,int *p2) 
{ 
	int temp = *p1;
	*p1=*p2;
	*p2=temp;
} 

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++) {
         if (arr[j] < pivot) {
             i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) {
         int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%5d ", arr[i]); 
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
    quickSort(arr, 0, n - 1);
	start=clock();
// time to sort elements
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Sorted elements are\n");
	printArray(arr,n);
	printf("Time taken for the sort to elements of an array\n",time_taken);
	return 0;
	


} 
