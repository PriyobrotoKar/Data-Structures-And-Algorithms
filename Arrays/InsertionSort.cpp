#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int s)
{
    int i = 1;
    while (i < s)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
        i++;
    }
}

int main()
{
    vector<int> arr{10, 6, 7, 9, 13, 20};
    int size = arr.size();
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}