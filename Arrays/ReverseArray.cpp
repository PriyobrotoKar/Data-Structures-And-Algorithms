#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int s = m + 1, e = arr.size() - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6};
    reverseArray(arr, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}