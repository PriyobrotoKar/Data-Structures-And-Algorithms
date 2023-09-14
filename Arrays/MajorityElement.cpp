#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(int a[], int size)
{
    // your code here
    int count = 1;
    int majEleIndx = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] == a[majEleIndx])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            majEleIndx = i;
        }
    }
    cout << majEleIndx << endl;
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == a[majEleIndx])
        {
            count++;
        }
    }
    if (count > size / 2)
        return a[majEleIndx];

    return -1;
}
int main()
{
    int arr[] = {3, 1, 3, 4, 2};
    cout << majorityElement(arr, 5) << endl;
}