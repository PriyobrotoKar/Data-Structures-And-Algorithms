#include <iostream>
using namespace std;

bool isSorted(int ar[], int n, string order = "asc", int x = 0)
{
    if (x >= n)
    {
        return true;
    }
    if (x == 0 || ((order == "asc") ? ar[x - 1] < ar[x] : ar[x - 1] > ar[x]))
    {
        return (true & isSorted(ar, n, order, x + 1));
    }

    return false;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << isSorted(arr, 1) << endl;
}