#include <iostream>
#include <stack>
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

int main()
{
    stack<int> stack;
    stack.push(7);
    stack.push(1);
    stack.push(4);
    stack.push(5);

    insertAtBottom(stack, 9);

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
