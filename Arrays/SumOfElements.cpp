#include <iostream>
using namespace std;

int sumOfElements(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
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
    cout << "The sum of elements are:" << sumOfElements(arr, size) << endl;
}