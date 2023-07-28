#include <iostream>
#include <vector>
using namespace std;

bool checkValidShuffle(string s, string str1, string str2)
{
    if (s.length() > (str1.length() + str2.length()))
    {
        return false;
    }
    string str = str1 + str2;
    for (int i = 0; i < str.size(); i++)
    {
        int f = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == str[i])
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    string first, second;
    cout << "Enter the no. of words:";
    cin >> n;
    cout << "Enter the first word:";
    cin >> first;
    cout << "Enter the second word:";
    cin >> second;
    string words[n];
    cout << "Enter the words:" << endl;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        words[i] = x;
    }
    for (int i = 0; i < n; i++)
    {

        if (checkValidShuffle(words[i], first, second))
        {
            cout << words[i] << " is a valid shuffle of " << first << " and " << second << endl;
        }
        else
        {
            cout << words[i] << " is not a valid shuffle of " << first << " and " << second << endl;
        }
    }
}