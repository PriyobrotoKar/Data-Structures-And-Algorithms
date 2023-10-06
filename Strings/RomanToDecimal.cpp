#include <iostream>
#include <algorithm>
using namespace std;

int romanToDecimal(string &str)
{
    // code here
    int v = 0;
    int sum = 0;
    vector<int> p;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == 'I')
            v = 1;
        else if (str[i] == 'V')
            v = 5;
        else if (str[i] == 'X')
            v = 10;
        else if (str[i] == 'L')
            v = 50;
        else if (str[i] == 'C')
            v = 100;
        else if (str[i] == 'D')
            v = 500;
        else if (str[i] == 'M')
            v = 1000;
        p.push_back(v);
    }

    for (int i = 0; i < p.size() - 1; i++)
    {
        if (p[i] < p[i + 1])
        {
            sum = sum - p[i];
        }
        else
            sum = sum + p[i];
    }
    sum = sum + p[p.size() - 1];
    return sum;
}
}

int main()
{
    string str = "MMDCCCXCIII";
    cout << romanToDecimal(str) << endl;
}