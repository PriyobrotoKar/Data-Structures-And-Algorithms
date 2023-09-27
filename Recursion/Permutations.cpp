#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        solve(nums, index + 1, ans);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permutate(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permutate(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << ",";
        }
        cout << "], ";
    }
    cout << "]";
}