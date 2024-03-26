#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2)
    {
        return -1;
    }

    int a = 0, b = 0;
    stack<char> stack;
    string validStr = "";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            stack.push(ch);
        }
        else
        {
            if (!stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                stack.push(ch);
            }
        }
    }

    while (!stack.empty())
    {
        if (stack.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        stack.pop();
    }

    return (a + 1) / 2 + (b + 1) / 2;
}

int main()
{
    string s = "{}}{}}";

    cout << findMinimumCost(s) << endl;
}
