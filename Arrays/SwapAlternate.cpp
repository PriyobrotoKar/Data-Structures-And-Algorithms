#include <iostream>
using namespace std;

void swapElements(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int arr[100];
    int size;
    cout << "Enter the size:";
    cin >> size;
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    swapElements(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}