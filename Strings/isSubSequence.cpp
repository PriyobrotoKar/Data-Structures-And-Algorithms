#include <iostream>
using namespace std;

bool isSubSequence(string str1, string str2)
{
    // Write your code here.
    int ptr1 = 0;
    int ptr2 = 0;

    while (ptr1 < str1.length() && ptr2 < str2.length())
    {
        if (str1[ptr1] == str2[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        else
        {
            ptr2++;
        }
    }

    if (ptr1 == str1.length())
    {
        return true;
    }

    return false;
}

int main()
{
    string s = "ABD";
    string t = "ABADE";

    cout << isSubSequence(s, t) << endl;
}
