#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> sort(int n, vector<int> &arr)
{
    // Write your code here.
    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        maxVal = max(arr[i], maxVal);
        minVal = min(arr[i], minVal);
    }

    vector<int> freq(maxVal - minVal + 1, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i] - minVal]++;
    }

    vector<int> sortedArr(n);

    int index = 0;
    for (int i = 0; i < maxVal - minVal + 1; ++i)
    {

        while (freq[i] > 0)
        {

            sortedArr[index] = i + minVal;

            index++;

            freq[i]--;
        }
    }

    return sortedArr;
}

int main()
{
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    int n = 5;
    arr = sort(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}