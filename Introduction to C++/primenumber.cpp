#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 2;
    while (i <= n / 2)
    {
        if (n % i == 0)
        {
            cout << "Not Prime Number" << endl;
            return 0;
        }
        i++;
    }
    cout << "Prime Number" << endl;
}