#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int elem)
{
    if (s.empty() || s.top() < elem)
    {
        s.push(elem);
        return;
    }

    int top = s.top();
    s.pop();
    sortedInsert(s, elem);
    s.push(top);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}

int main()
{
    stack<int> stack;
    stack.push(5);
    stack.push(-2);
    stack.push(9);
    stack.push(-7);
    stack.push(3);

    sortStack(stack);

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
