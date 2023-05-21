#include <iostream>
using namespace std;
int bitwiseComplement(int n)
{
    int x = 1;
    while (x < n)
    {
        x = 2 * x + 1;
    }
    return n ^ x;
}
int main()
{
    cout << bitwiseComplement(5) << endl;
}
