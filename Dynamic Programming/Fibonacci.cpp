#include <iostream>
#include <vector>
using namespace std;

int nthFibonacciNumber(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = nthFibonacciNumber(n - 1, dp) + nthFibonacciNumber(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter N:";
    cin >> n;

    vector<int> dp(n + 1, -1);

    int ans = nthFibonacciNumber(n, dp);

    cout << n << "th Fibonacci Number is " << ans << endl;
}
