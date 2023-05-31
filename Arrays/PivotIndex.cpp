#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int ls = 0, rs = 0, start = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        rs = rs + nums[i];
    }
    while (start < nums.size())
    {
        rs = rs - nums[start];
        if (ls == rs)
        {
            return start;
        }
        ls = ls + nums[start];
        start++;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums) << endl;
}