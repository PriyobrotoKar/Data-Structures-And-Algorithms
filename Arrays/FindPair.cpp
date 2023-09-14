#include <iostream>
#include <algorithm>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    // Initializing two pointers at index 0 and 1
    int i = 0;
    int j = 1;

    // Loop until one of the pointers goes out of bounds
    while (i < size && j < size)
    {
        // If the difference between the elements at the two pointers
        // is equal to n, return true
        if (i != j && arr[j] - arr[i] == n)
        {
            return true;
        }
        // If the difference is less than n, increment the second pointer
        else if (arr[j] - arr[i] < n)
            j++;
        // If the difference is greater than n, increment the first pointer
        else
            i++;
    }

    // If no pair is found, return false
    return false;
}

int main()
{
    int ar[] = {5, 20, 3, 2, 5, 80};
    cout << findPair(ar, 6, 78) << endl;
}