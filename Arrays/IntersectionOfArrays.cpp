#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> arr;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int temp = -1;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (temp != nums1[i])
        {
            temp = nums1[i];
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                    break;

                if (nums1[i] == nums2[j])
                {
                    arr.push_back(nums1[i]);
                    break;
                }
            }
        }
    }
    return arr;
}