#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(vector<int> &arr)
{
    // Write your code here.
    int len = arr.size();
    int s = 0, e = len - 1;
    int mid = s + (e - s) / 2;

    while (mid != s && mid != e)
    {
        int lsum = 0, rsum = 0;
        for (int i = 0; i < mid; i++)
        {
            lsum = lsum + arr[i];
        }
        for (int i = mid + 1; i < len; i++)
        {
            rsum = rsum + arr[i];
        }
        if (lsum > rsum)
        {
            mid--;
        }
        else if (lsum < rsum)
        {
            mid++;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {14,
                       2,
                       10,
                       15,
                       9,
                       15,
                       1,
                       3,
                       22,
                       7,
                       9,
                       4,
                       4};

    cout << findEquilibriumIndex(arr) << endl;
}