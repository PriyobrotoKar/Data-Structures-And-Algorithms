#include <iostream>
#include <algorithm>
using namespace std;

int middleUsingArray(int A, int B, int C)
{
    int arr[3] = {A, B, C};
    sort(arr, arr + 3);
    return arr[1];
}
int middleUsingFunc(int A, int B, int C)
{
    int mi = min(min(A, B), C);
    int ma = max(max(A, B), C);
    return A + B + C - (mi + ma);
}
int middle(int A, int B, int C)
{
    if (A > B && A < C || A < B && A > C)
    {
        return A;
    }
    if (B < A && B > C || B > A && B < C)
    {
        return B;
    }
    return C;
}
int main()
{
    int x, y, z;
    cout << "Enter 3 nos:";
    cin >> x >> y >> z;
    cout << middleUsingArray(x, y, z) << endl;
    cout << middleUsingFunc(x, y, z) << endl;
    cout << middle(x, y, z) << endl;
}