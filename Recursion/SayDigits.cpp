#include <iostream>
using namespace std;

const string digits[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

string sayDigits(long x)
{
    if (x == 0)
    {
        return "";
    }
    if (x < 10)
    {
        return sayDigits(x / 10) + digits[x % 10];
    }
    return sayDigits(x / 10) + " " + digits[x % 10];
}

int main()
{
    long x;
    cout << "Enter a no." << endl;
    cin >> x;
    cout << x << endl;
    cout << sayDigits(x) << endl;
}