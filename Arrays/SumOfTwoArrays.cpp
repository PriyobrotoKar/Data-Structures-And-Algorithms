#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
}

vector<int> sumOfTwoArrays(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> v;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
    }
    return reverse(v);
}

int main()
{
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums2{1, 2, 3, 4};
    vector<int> ans = sumOfTwoArrays(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}