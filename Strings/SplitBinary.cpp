#include <iostream>
#include <vector>
using namespace std;

int checkBalancedString(string s)
{
    int size = s.size();
    int count0 = 0;
    int count1 = 0;

    int ctn = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
        if (count0 == count1)
        {
            ctn++;
        }
    }

    if (ctn)
    {
        return ctn;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string str;
    cout << "Enter a string:";
    cin >> str;
    cout << checkBalancedString(str) << endl;
}