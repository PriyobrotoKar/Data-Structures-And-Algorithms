#include <stack>
#include <iostream>
using namespace std;

void insertAtBottom(stack<int> &s, int elem)
{
    if (s.empty())
    {
        s.push(elem);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, elem);
    s.push(num);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, num);
}

int main()
{
    stack<int> stack;
    stack.push(7);
    stack.push(1);
    stack.push(4);
    stack.push(5);

    reverseStack(stack);

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
