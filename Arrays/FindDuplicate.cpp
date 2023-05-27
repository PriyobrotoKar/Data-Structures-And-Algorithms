#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return 0;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(cin.get());
    }

    cout << findDuplicate(nums) << endl;
}