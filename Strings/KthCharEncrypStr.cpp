#include <iostream>
using namespace std;

string kThCharaterOfDecryptedString(string s, long long k)
{
    //  Write your code here.
    int count = 0;
    string decryptedString = "";
    string subStr = "";

    for (int i = 0; i < s.length() || count > 0; i++)
    {

        char ch = s[i];

        if (ch >= 'a' && ch <= 'z')
        {
            string temp = subStr;
            while (count > 0)
            {
                subStr = "";
                decryptedString += temp;
                count--;
            }
            subStr += ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            // cout << count << ch << endl;
            count = (count * 10) + (ch - '0');
        }
    }

    return decryptedString;
}

int main()
{
    string inp = "ab12c3";
    int k = 20;

    cout << kThCharaterOfDecryptedString(inp, k) << endl;
}