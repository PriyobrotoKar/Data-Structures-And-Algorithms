#include <iostream>
#include <vector>
using namespace std;

void rowWiseSum(vector<vector<int>> &arr, int m, int n)
{
    int maxSum = INT16_MIN;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << " is " << sum << endl;
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }
    cout << "Largest Row Sum is " << maxSum << endl;
}
void columnWiseSum(vector<vector<int>> &arr, int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << " is " << sum << endl;
    }
}
int main()
{
    int r, c;
    cout << "Enter the no. of rows:";
    cin >> r;
    cout << "Enter the no. of columns:";
    cin >> c;
    cout << "Enter the elements:" << endl;
    vector<vector<int>> ar(r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int temp;
            cin >> temp;
            ar[i].push_back(temp);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    rowWiseSum(ar, r, c);
    columnWiseSum(ar, r, c);
}