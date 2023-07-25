#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s)
{
    string rev = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        rev = rev + s.at(i);
    }

    return (rev == s);
}

int main()
{
    string s = "abba";
    cout << isPalindrome(s) << endl;
}