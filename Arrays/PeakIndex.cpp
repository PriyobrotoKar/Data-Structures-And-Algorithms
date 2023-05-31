#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid + 1] > arr[mid])
        {
            s = mid + 1;
        }
        else if (arr[mid + 1] < arr[mid])
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    vector<int> nums = {0, 1, 2, 1, 5};
    cout << peakIndexInMountainArray(nums) << endl;
}