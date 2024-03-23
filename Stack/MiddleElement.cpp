#include <iostream>
#include <stack>
using namespace std;

void removeMiddleElement(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        cout << "Removed " << s.top() << endl;
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    removeMiddleElement(s, ++count, size);

    s.push(num);
}

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    removeMiddleElement(stack, 0, stack.size());

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
