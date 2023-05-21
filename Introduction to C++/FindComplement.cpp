#include <iostream>
using namespace std;
int findComplement(int num)
{
    int x = 1;
    while (x < num)
    {
        x = 2 * x + 1;
    }
    return num ^ x;
}
int main()
{
    cout << findComplement(5) << endl;
}
