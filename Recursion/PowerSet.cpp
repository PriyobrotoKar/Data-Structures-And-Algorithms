#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    subsets(nums, output, index + 1, ans);

    output.push_back(nums[index]);
    subsets(nums, output, index + 1, ans);
}

int main()
{
    vector<int> set = {1, 2, 3};
    vector<int> output;
    vector<vector<int>> ans;
    subsets(set, output, 0, ans);
    cout << ans.size() << endl;
}