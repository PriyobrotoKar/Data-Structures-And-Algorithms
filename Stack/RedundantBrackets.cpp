#include <iostream>
#include <stack>
using namespace std;

bool isClosingParenthesis(char ch)
{
    if (ch == ')')
    {
        return true;
    }
    return false;
}

char isOpeningParenthesis(char ch)
{
    if (ch == '(')
    {
        return true;
    }
    return false;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    return false;
}

bool isValidCharacter(char ch)
{
    if (isOpeningParenthesis(ch) || isClosingParenthesis(ch) || isOperator(ch))
    {
        return true;
    }
    return false;
}

bool findRedundantBrackets(string &s)
{
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (!isValidCharacter(ch))
        {
            continue;
        }

        if (isClosingParenthesis(ch))
        {
            if (isOperator(stack.top()))
            {
                while (!isOpeningParenthesis(stack.top()))
                {
                    stack.pop();
                }
                stack.pop();
            }
            else
            {
                return true;
            }
        }
        else
        {
            stack.push(ch);
        }
    }

    if (!stack.empty() && isOperator(stack.top()))
    {
        return false;
    }

    return !stack.empty();
}

//(((a+b))+(c+d))
int main()
{
    string exp = "(a+b)";
    cout << findRedundantBrackets(exp) << endl;
}
