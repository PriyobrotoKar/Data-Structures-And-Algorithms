#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s)
{
    long long ans = 0;
    bool isNegative = false;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '-')
        {
            if (s[i + 1] == '-' || s[i + 1] == '+' || (s[i + 1] < '0' && s[i + 1] > '9'))
            {
                return 0;
            }
            if (i != 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
            {
                return 0;
            }
            isNegative = true;
        }
        else if (ch == '+')
        {
            if (s[i + 1] == '-' || s[i + 1] == '+' || (s[i + 1] < '0' || s[i + 1] > '9'))
            {
                return 0;
            }
            if (i != 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
            {
                return 0;
            }
            isNegative = false;
        }
        else if (ch >= '0' && ch <= '9')
        {
            //  cout << (s[i+1] < '0'||s[i+1] > '9' )<< endl;
            if (ans > INT8_MAX && isNegative)
                return INT8_MIN;
            else if (ans > INT8_MAX && !isNegative)
                return INT_MAX;
            ans = (ans * 10) + ch - '0';
            if (i != s.length() - 1 && (s[i + 1] < '0' || s[i + 1] > '9'))
            {
                break;
            }
        }
        else if (ch != ' ')
        {
            break;
        }
    }

    ans = isNegative ? -1 * ans : ans;

    if (ans < INT8_MIN)
        return INT_MIN;
    else if (ans > INT8_MAX)
        return INT_MAX;
    return ans;
}

int main()
{
    string s = "-9329879231231  ";
    cout << myAtoi(s) << endl;
}