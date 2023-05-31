#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> &arr, int size, int k)
{
    int ans = -1;
    int s = 0, e = size - 1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOcc(vector<int> &arr, int size, int k)
{
    int ans = -1;
    int s = 0, e = size - 1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 2, 2, 1, 5};
    int target = 2;
    int s = nums.size();
    cout << firstOcc(nums, s, target) << endl;
    cout << lastOcc(nums, s, target) << endl;
}