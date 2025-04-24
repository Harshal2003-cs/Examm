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

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
    }
}

// Function to read an array from a file
int readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading data from file.\n");
            fclose(file);
            return 0;
        }
    }
    
    fclose(file);
    return 1;
}

int main() {
    int n, choice;
    
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Choose input method:\n");
    printf("1. Generate random numbers\n");
    printf("2. Read from file (data.txt)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        generateRandomArray(arr, n);
    } else if (choice == 2) {
        if (!readArrayFromFile("data.txt", arr, n)) {
            free(arr);
            return 1;
        }
    } else {
        printf("Invalid choice!\n");
        free(arr);
        return 1;
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Measure sorting time
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
