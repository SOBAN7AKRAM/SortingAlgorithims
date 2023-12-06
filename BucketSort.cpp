#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n)
{
    // create an empty array equal to initial array size 
    vector<float>* b =new vector<float>[n];

    // put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    
    // sort each bucket of the array
    for (int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    // concentate all buckets into array
    int index = 0;
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            arr[index] = b[i][j];
            index++;
        }
    }
}

int main()
{
    float arr[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}