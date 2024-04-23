#include <iostream>
#include <queue>
using namespace std;

string FirstNonRepeating(string A)
{
    string ans = "";
    queue<char> q;
    unordered_map<char, int> count;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string inp = "aabc";
    cout << FirstNonRepeating(inp) << endl;
}