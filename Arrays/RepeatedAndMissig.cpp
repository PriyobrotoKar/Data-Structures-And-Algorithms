#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    int repeated = 0;
    long size = n;
    long sum = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (arr[i] == arr[i + 1] && repeated == 0)
        {
            repeated = arr[i];
        }
    }
    int missing = (size * (size + 1) / 2) - (sum - repeated);
    return {repeated, missing};
}

int main()
{
    vector<int> ar = {1, 3, 3};
    cout << findTwoElement(ar, ar.size())[0] << " " << findTwoElement(ar, ar.size())[1] << endl; //* Output: repeated missing => 3 2
}