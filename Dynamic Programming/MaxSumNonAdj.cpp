#include <iostream>
#include <vector>
using namespace std;

int maxSumTillIndex(vector<int> nums, int ind, vector<int> &dp)
{
    if (ind == 0)
    {
        return nums[ind];
    }

    if (ind < 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = nums[ind] + maxSumTillIndex(nums, ind - 2, dp);
    int notPick = 0 + maxSumTillIndex(nums, ind - 1, dp);

    dp[ind] = max(pick, notPick);

    return dp[ind];
}

int maxSumOfNonAdjacent(vector<int> nums)
{
    vector<int> dp(nums.size(), -1);
    int ans = maxSumTillIndex(nums, nums.size() - 1, dp);
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maxSumOfNonAdjacent(nums) << endl;
}
