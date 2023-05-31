#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return x;
    int s = 1, e = x;
    int ans;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid > x / mid)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    cout << mySqrt(8) << endl;
}