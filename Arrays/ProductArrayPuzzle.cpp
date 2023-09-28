#include <iostream>
#include <vector>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    vector<long long int> P;
    for (int j = 0; j < n; j++)
    {
        long long int prod = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != j)
            {
                prod = prod * nums[i];
            }
        }
        P.push_back(prod);
    }
    return P;
}

int main()
{
    vector<long long int> nums = {10, 3, 5, 6, 2};
    vector<long long int> ans = productExceptSelf(nums, nums.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}