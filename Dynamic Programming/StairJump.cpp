#include <iostream>
#include <vector>
using namespace std;

int frogJump(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int cost2 = INT_MAX;
    int cost1 = frogJump(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
    {
        cost2 = frogJump(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }

    return min(cost1, cost2);
}

int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    vector<int> h = {10, 20, 30, 10};

    cout << frogJump(n, h, dp) << endl;
}
