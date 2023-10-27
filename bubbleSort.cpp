#include <iostream>
using namespace std;
void bubbleSort(int arr[], const int n);
template <typename T>
void selectionSort(T arr[], const int n);
void insertionSort(int arr[], const int n);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int main()
{
    const int n = 14;
    int arr[n] = {4,3,2,5,3,6,2,6, 10, 15, 20, 1, 2, 0};
    // string arr[n] = {"Soban", "Numan", "Ahmed", "Sohaib"};
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n);
    quickSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void bubbleSort(int arr[],const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
}