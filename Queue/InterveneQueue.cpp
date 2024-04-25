#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interveneQueue(queue<int> &q)
{
    int n = q.size() / 2;

    stack<int> s;

    int temp = n;
    while (temp > 0)
    {
        s.push(q.front());
        q.pop();
        temp--;
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    temp = n;
    while (temp > 0)
    {
        q.push(q.front());
        q.pop();
        temp--;
    }

    temp = n;
    while (temp > 0)
    {
        s.push(q.front());
        q.pop();
        temp--;
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> inp;
    inp.push(11);
    inp.push(12);
    inp.push(13);
    inp.push(14);
    inp.push(15);
    inp.push(16);
    inp.push(17);
    inp.push(18);

    interveneQueue(inp);

    while (!inp.empty())
    {
        cout << inp.front() << " ";
        inp.pop();
    }
}