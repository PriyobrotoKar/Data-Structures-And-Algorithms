#include <iostream>
#include <vector>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;

    int maxSum = 0;
    int rowIndex = 0;

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += mat[i][j];
        }
        if (sum > maxSum)
        {
            maxSum = sum;
            rowIndex = i;
        }
    }
    return {rowIndex, maxSum};
}

int main()
{
    int r, c, x;
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
    vector<int> ans = rowAndMaximumOnes(ar);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << endl;
    }
}