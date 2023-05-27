#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{0, 1, 0, 1, 1, 0};
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
            continue;
        }
        if (arr[i] == 0)
        {
            i++;
        }
        if (arr[j] == 1)
        {
            j--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}