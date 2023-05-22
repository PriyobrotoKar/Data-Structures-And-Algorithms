#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int c = 0;
    while (n)
    {
        if (n & 1)
        {
            c++;
        }
        n = n >> 1;
    }
    return c;
}

int main()
{
    int x, y;
    cout << "Enter two numbers:" << endl;
    cin >> x >> y;
    cout << "The no. of set bits are " << countSetBits(x) + countSetBits(y) << endl;
}