#include <stdio.h>
#include<time.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; // Return index if found
        if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Return -1 if not found
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start,end;
    sortArray(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    start = clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    if (result != -1)
    {
        printf("Element %d found at position %d.\n", target, result + 1);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }
    printf("time required %f",time_taken);
    return 0;
    
}

