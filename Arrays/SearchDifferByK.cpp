#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int x, int k)
{
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }
        i = i + max(i, abs((arr[i] - x) / k));
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 6};
    int x = 8;
    int k = 1;
    cout << search(arr, x, k) << endl;
}