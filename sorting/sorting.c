#include <stdio.h>
#include <stdlib.h>

// ---------- Function Declarations ----------
void bubbleSort(int arr[], int n);
void cocktailShakerSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

// ---------- Bubble Sort ----------
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------- Cocktail Shaker Sort ----------
void cocktailShakerSort(int arr[], int n)
{
    int swapped = 1, start = 0, end = n - 1, temp, i;

    while (swapped)
    {
        swapped = 0;
        for (i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        for (i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        start++;
    }
}

// ---------- Insertion Sort ----------
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------- Selection Sort ----------
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ---------- Utility to print array ----------
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------- Main Function ----------
int main()
{
    int arr[50], n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Cocktail Shaker Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(arr, n);
            printf("Array sorted using Bubble Sort:\n");
            printArray(arr, n);
            break;

        case 2:
            cocktailShakerSort(arr, n);
            printf("Array sorted using Cocktail Shaker Sort:\n");
            printArray(arr, n);
            break;

        case 3:
            insertionSort(arr, n);
            printf("Array sorted using Insertion Sort:\n");
            printArray(arr, n);
            break;

        case 4:
            selectionSort(arr, n);
            printf("Array sorted using Selection Sort:\n");
            printArray(arr, n);
            break;

        case 5:
            printf("Current Array:\n");
            printArray(arr, n);
            break;

        case 6:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
