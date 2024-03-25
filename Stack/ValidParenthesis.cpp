#include <iostream>
#include <stack>
using namespace std;

bool isClosingParenthesis(char ch)
{
    if (ch == ')' || ch == '}' || ch == ']')
    {
        return true;
    }
    return false;
}

char getRespectiveOpeningParenthesis(char ch)
{
    switch (ch)
    {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';

    default:
        return '\0';
    }
}

bool isValidParenthesis(string expression)
{
    if (expression.length() == 1)
    {
        return false;
    }

    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (isClosingParenthesis(ch))
        {
            char openingParenthesis = getRespectiveOpeningParenthesis(ch);
            if (s.empty())
            {
                return true;
            }
            if (s.top() != openingParenthesis)
            {
                return false;
            }
            s.pop();
        }
        else
        {
            s.push(expression[i]);
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "]";
    if (isValidParenthesis(str))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}
