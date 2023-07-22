#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrixSum(vector<vector<int>> &nums)
{
    int row = nums.size();
    int col = nums[0].size();

    for (int i = 0; i < row; i++)
    {
        sort(nums[i].begin(), nums[i].end());
    }

    int score = 0;

    for (int j = 0; j < col; j++)
    {
        int max = nums[0][j];
        for (int i = 1; i < row; i++)
        {
            if (nums[i][j] > max)
            {
                max = nums[i][j];
            }
        }
        score += max;
    }
    return score;
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
    cout << matrixSum(ar) << endl;
}