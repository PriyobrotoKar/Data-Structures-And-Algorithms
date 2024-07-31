#include <iostream>
#include <vector>
using namespace std;

int getMinNumberOfCoins(int target, vector<int> coins, vector<int> &dp)
{
    if (target == 0)
    {
        return 0;
    }

    if (target < 0)
    {
        return INT_MAX;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        dp[target] = getMinNumberOfCoins(target - coins[i], coins, dp);

        if (dp[target] != INT_MAX)
        {
            mini = min(mini, 1 + dp[target]);
        }
    }

    return mini;
}

int main()
{
    int amount = 10;
    vector<int> coins = {1, 3, 4};

    vector<int> dp(amount + 1, -1);

    int minNumberOfCoins = getMinNumberOfCoins(10, coins, dp);

    cout << "Minimum number of coins : " << minNumberOfCoins << endl;

    return 0;
}
