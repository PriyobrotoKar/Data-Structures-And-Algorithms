#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s)
{
    s = s + " ";
    string rev = "", wrd = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            wrd = wrd + s[i];
        }
        else
        {
            if (wrd != "")
            {

                rev = wrd + " " + rev;
                wrd = "";
            }
        }
    }
    return rev.substr(0, rev.length() - 1);
}

int main()
{
    string str = "   Hello world ";
    string rev = reverseWords(str);
    for (int i = 0; i < rev.length(); i++)
    {
        cout << rev[i];
    }
    cout << endl;
}
