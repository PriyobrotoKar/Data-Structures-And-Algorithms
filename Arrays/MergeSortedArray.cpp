#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    int p1 = 0, p2 = 0;
    while (p1 < arr1.size() && p2 < arr2.size())
    {
        if (arr1[p1] < arr2[p2])
        {
            arr3.push_back(arr1[p1++]);
        }
        else
        {
            arr3.push_back(arr2[p2++]);
        }
    }
    while (p1 < arr1.size())
    {
        arr3.push_back(arr1[p1++]);
    }
    while (p2 < arr2.size())
    {
        arr3.push_back(arr2[p2++]);
    }
}

int main()
{
    vector<int> nums1{1, 3, 5, 7, 9};
    vector<int> nums2{2, 4, 6};
    vector<int> nums3;
    mergeArrays(nums1, nums2, nums3);
    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i] << " ";
    }
}