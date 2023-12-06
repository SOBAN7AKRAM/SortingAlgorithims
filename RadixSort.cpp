#include <iostream>
using namespace std;
// get max value
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void countingSort(int array[], int size, int place, int max)
{
    int* output = new int[size];
    int* count = new int[max];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}
void radixSort(int array[], int size)
{
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(array, size, place, 10);
    }
}
// Print an array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    radixSort(array, n);
    printArray(array, n);
}

// Radix sort is a non-comparative integer sorting algorithm

// It has a time complexity of O(d * (n + b)), where d is the number of digits, n is the number of elements, and b is the base of the number system being used.

// Time Complexity	 
// Best	O(n+k)
// Worst	O(n+k)
// Average	O(n+k)

// not inPlace
// stable