#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    char ch = chars[0];
    int c = 0;
    vector<char> a;
    for (int i = 0; i < n; i++)
    {
        if (chars[i] == ch)
        {
            c++;
        }
        else
        {
            if (c == 1)
            {

                a.push_back(ch);
            }
            else
            {
                a.push_back(ch);
                for (int j = 0; j < to_string(c).length(); j++)
                {

                    a.push_back(to_string(c)[j]);
                }
            }
            ch = chars[i];
            c = 1;
        }
    }
    if (c == 1)
    {

        a.push_back(ch);
    }
    else
    {
        a.push_back(ch);
        for (int j = 0; j < to_string(c).length(); j++)
        {

            a.push_back(to_string(c)[j]);
        }
    }
    chars = a;
    return a.size();
}

int main()
{
    vector<char> str = {'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    compress(str);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;
}