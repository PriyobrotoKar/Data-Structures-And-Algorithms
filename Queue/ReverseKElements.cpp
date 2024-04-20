#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;

    while (s.size() != k)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    while (k - 1 != 0)
    {
        q.push(q.front());
        q.pop();
        k--;
    }

    return q;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    q = modifyQueue(q, k);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}