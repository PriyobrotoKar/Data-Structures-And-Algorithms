#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &ar, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[minInd])
                minInd = j;
        }
        swap(ar[minInd], ar[i]);
    }
}

int main()
{
    vector<int> arr{10, 20, 20, 30, 10};
    selectionSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}