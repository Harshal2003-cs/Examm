#include <stdio.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = 0;
    
    while ((i <= mid) && (j <= high)) {
        if (arr[i] <= arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    
    while (i <= mid)
        b[k++] = arr[i++];
    
    while (j <= high)
        b[k++] = arr[j++];
    
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = b[k];
}

void mergesort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);  // Corrected function call
    }
}

void printArray(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%5d ", arr[i]); 
    printf("\n"); 
}

int main() { 
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\n");
    printArray(arr, n);

    clock_t start, end;
    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();

    printf("Sorted elements are:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", time_taken);

    return 0;
}