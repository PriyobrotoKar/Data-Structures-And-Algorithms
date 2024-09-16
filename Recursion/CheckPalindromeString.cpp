#include <iostream>
using namespace std;

bool isPalindrome(string str, int i)
{
    int n = str.length();
    if (i >= n - i - 1)
    {
        return true;
    }
    if (str[i] != str[n - i - 1])
    {
        return false;
    }
    return isPalindrome(str, ++i);
}

int main()
{
    string str = "MADAM";

    cout << isPalindrome(str, 0) << endl;
}
