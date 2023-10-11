#include <iostream>
#include <math.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    // code here
    if (C == 0)
    {
        return (A == B) ? 1 : 0;
    }
    else
    {
        double n = (double(B - A) / C) + 1;
        return (floor(n) == n && n > 0) ? 1 : 0;
    }
}

int main()
{
    int A = 1, B = 3, C = 2;
    cout << floor(-3) << endl;
    cout << inSequence(A, B, C) << endl;
}