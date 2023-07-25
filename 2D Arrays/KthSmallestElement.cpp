#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    int n = matrix.size();

    while (i < n && j < n)
    {
        if (j != n - 1)
        {
            ans.push_back(matrix[i][j]);
            j++;
        }
        else
        {
            ans.push_back(matrix[i][j]);
            j = 0;
            i++;
        }
    }
    sort(ans.begin(), ans.end());
    return ans[k - 1];
}

int main()
{
    vector<vector<int>> Mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << kthSmallest(Mat, 8) << endl;
}