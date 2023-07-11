#include <iostream>
#include <vector>
using namespace std;

pair<int, int> linearSearch(int arr[][3], int m, int n, int target)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main()
{
    int ar[3][3];
    int x;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> ar[i][j];
        }
    }
    cout << "Enter the element to be searched" << endl;
    cin >> x;
    pair<int, int> pos = linearSearch(ar, 3, 3, x);
    if (pos.first != -1)
    {
        cout << "Element is found at row " << pos.first + 1 << " and column " << pos.second + 1 << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }
}