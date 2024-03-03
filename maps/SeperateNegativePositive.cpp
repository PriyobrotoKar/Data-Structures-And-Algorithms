#include <iostream>
#include <vector>
using namespace std;
vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    // Write your code here.
    int pointer = 0;
    int temp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans.insert(ans.begin(), nums[i]);
        }
        else
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 5, -1, 2, -8};
    vector<int> output = separateNegativeAndPositive(nums);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " " << endl;
    }
}
