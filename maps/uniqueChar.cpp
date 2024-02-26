#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

char firstNonRepeatingCharacter(string str)
{

    // Write your code here
    int n = str.size();

    map<char, int> mp;

    for (int i = 0; i < n; i++)
    {

        mp[str[i]]++;
    }

    char ans = str[0];

    for (int i = 0; i < n; i++)
    {

        if (mp[str[i]] == 1)
        {

            ans = str[i];

            break;
        }
    }

    return ans;
}

int main()
{
    string str = "AabBcC";
    cout << firstNonRepeatingCharacter(str) << endl;
}