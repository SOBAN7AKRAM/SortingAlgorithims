#include <iostream>
#include <limits.h>
using namespace std;
void bubbleSort(int arr[], const int n);
template <typename T>
void selectionSort(T arr[], const int n);
void insertionSort(int arr[], const int n);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void countingSort(int arr[], int size);
int main()
{
    const int n = 14;
    int arr[n] = {4,3,2,5,3,6,2,6, 10, 15, 20, 1, 2, 0};
    // string arr[n] = {"Soban", "Numan", "Ahmed", "Sohaib"};
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n);
    // quickSort(arr, 0, n);
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void bubbleSort(int arr[],const int n)
{
    // loop that how many time we make comparison
    for (int i = 0; i < n - 1; i++)
    {
        // n - 1 - i because after every iteration last elements is sorted
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    // time complexity 0(n^2)
    // it is an inplace algorithim (no additional memory needed)
    // it is a stable algorithim (element order is preserved)
}
template<typename T>
void selectionSort(T arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i; j < n; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }

    // time complexity: 0(n^2)
    // not stable 
    // inplace algorithim

}
void insertionSort(int arr[], const int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // compare key with each element on left until a smaller than it is found
        // for decending order change key < arr[j] to key > arr[j]
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // time complexity:
    // Worst or Average Case: 0(n ^ 2)
    // Best Case: 0(n)
    // (When is almost sorted)
    // inPlace Algorithim
    // Stable Algorithim

}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }


    // time complexity: 0(n log n)
    // stable algorithim
    // not inplace
    // not suitable for small dataSets
}
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    int* temp = new int[high - low + 1];
    while (i <= mid && j <= high)
    {
        // copy the smallest element from the 2 partial array and store them in temp array
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++,k++;
        }
        else
        {
            temp[k] = arr[j];
            j++,k++;
        }
    }
    // loop if any of the array is not completely traversed
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++, k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++, k++;
    }
    // copy the temp sorted array into original array
    for (int t = 0; t <= high - low; t++)
    {
        arr[low + t] = temp[t];
    }
    delete[] temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while (i <= j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }

    //  Best Case: Ω (N log (N))
    //  The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
    //  In this case, the algorithm will make balanced partitions, leading to efficient Sorting.

    // Average Case: θ ( N log (N))

    // Worst Case: O(N2)
    // The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly   unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest     or largest element

    // not stable

    // inPlace
}
void countingSort(int arr[], int size)
{
    int max = INT_MIN;
    // to find max value from the initial array
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    // declare a new array of size max+1
    int* count = new int[max + 1];
    // initialize new array with 0
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    // increment value at count array index [index will be the value of initial array]
    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    int i = 0; int j = 0;
    // loop to copy value from count array to arr
    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }


    // Time Complexity: O(N+M), where N and M are the size of inputArray[] and countArray[] respectively.
    // Worst-case: O(N+M).
    // Average-case: O(N+M).
    // Best-case: O(N+M).

    // Counting sort is inefficient if the range of values to be sorted is very large.
    // Counting sort is a stable algorithm.
    // Counting sort is not an In-place sorting algorithm
}