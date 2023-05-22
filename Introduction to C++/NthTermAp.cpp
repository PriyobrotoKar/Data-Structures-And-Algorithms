#include <iostream>
using namespace std;

int nthTerm(int n)
{
    return 3 * n + 7;
}

int main()
{
    int x;
    cout << "Enter the term:";
    cin >> x;
    cout << "The " << x << "th term is: " << nthTerm(x) << endl;
}