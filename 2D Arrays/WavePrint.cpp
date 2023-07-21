#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int j = 0; j < mCols; j++)
    {
        if (j & 1)
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][j]);
            }
        }
        else
        {
            for (int i = 0; i < nRows; i++)
            {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
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
    vector<int> ansarr = wavePrint(ar, r, c);
    for (int i = 0; i < ansarr.size(); i++)
    {
        cout << ansarr[i] << " ";
    }
}