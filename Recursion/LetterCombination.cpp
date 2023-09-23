#include <iostream>
#include <vector>
using namespace std;

void letterCombination(string digit, string output, int index, string mapping[], vector<string> &ans)
{
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    string mapValue = mapping[digit[index] - '0'];

    for (int i = 0; i < mapValue.length(); i++)
    {
        output.push_back(mapValue[i]);
        letterCombination(digit, output, index + 1, mapping, ans);
        output.pop_back();
    }
}

int main()
{
    vector<string> ans;
    string output;
    string digits = "234";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombination(digits, output, 0, mapping, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}