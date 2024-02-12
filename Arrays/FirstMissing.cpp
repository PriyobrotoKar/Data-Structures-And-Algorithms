#include <iostream>
using namespace std;

int firstMissing(int arr[], int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            arr[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (index < n)
        {
            arr[index] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << firstMissing(arr, 10) << endl;
}