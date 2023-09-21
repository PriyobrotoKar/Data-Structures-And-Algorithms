#include <iostream>
using namespace std;

string reverse(string s)
{
    if (s.length() == 1 || s.length() == 0)
    {
        return s;
    }

    int last = s.length() - 1;
    return s[last] + reverse(s.substr(0, last));
}

int main()
{
    string wrd;
    cout << "Enter a string:";
    cin >> wrd;
    cout << reverse(wrd) << endl;
}