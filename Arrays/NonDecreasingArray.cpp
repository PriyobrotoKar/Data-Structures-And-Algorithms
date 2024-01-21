#include <iostream>
using namespace std;

bool isPossible(int *arr, int n)
{
    //  Write your code here.
    bool isModified = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            continue;
        }
        if (isModified)
        {
            return false;
        }

        if (i == 0 || arr[i + 1] >= arr[i - 1])
        {
            arr[i] = arr[i + 1];
        }
        else
        {
            arr[i + 1] = arr[i];
        }

        isModified = true;
    }
    return true;
}

int main()
{
    int arr[10] = {-41, -40, -22, -14, -14, -1, 17, 59, -130, 92};
    cout << isPossible(arr, 10) << endl;
}