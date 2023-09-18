#include <iostream>
using namespace std;

int sumOfArray(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arr[size - 1] + sumOfArray(arr, size - 1);
}

int main()
{
    int ar[5] = {2, 4, 9, 9, 9};
    cout << sumOfArray(ar, 5) << endl;
}