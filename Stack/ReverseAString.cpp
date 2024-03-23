#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s)
{
    string ans = "";
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }

    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }
    return ans;
}

int main()
{

    string str = "India";
    cout << reverseString(str) << endl;
}
