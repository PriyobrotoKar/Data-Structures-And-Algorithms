#include <iostream>
#include <math.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    // code here
    double n = (double(B - A) / C) + 1;
    // double n = float(4 / 3);
    // int n = 0;
    cout << n << endl;
    return (floor(n) == n) ? 1 : 0;
}

int main()
{
    int A = 1, B = 3, C = 2;
    cout << floor(-3) << endl;
    cout << inSequence(A, B, C) << endl;
}