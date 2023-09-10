#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int len = strs.size(), f = false;
    string ans = "";
    for (int j = 0; j < strs[0].length(); j++)
    {

        for (int i = 1; i < len; i++)
        {
            if (strs[i].length() > j)
            {
                if (strs[i][j] != strs[0][j])
                {
                    f = true;
                    break;
                }
            }
            else
            {
                f = true;
                break;
            }
        }
        if (f)
        {
            break;
        }
        else
        {
            ans = ans + strs[0][j];
        }
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower",
                           "flow",
                           "fing"};
    cout << longestCommonPrefix(strs) << endl;
}