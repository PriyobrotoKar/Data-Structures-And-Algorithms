#include <iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int key)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] > key)
    {
        end = mid - 1;
        return binarySearch(arr, start, end, key);
    }

    start = mid + 1;
    return binarySearch(arr, start, end, key);
}

int main()
{
    int ar[5] = {2, 4, 6, 8, 19};
    cout << binarySearch(ar, 0, 4, 19) << endl;
}