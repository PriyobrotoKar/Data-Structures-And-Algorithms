#include <iostream>
#include <vector>
using namespace std;
void findCharacterCount(string str)
{
    int arr[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        int index;
        if (ch >= 'a' && ch <= 'z')
        {
            index = ch - 'a';
            arr[index]++;
        }
        else
        {
            index = ch - 'A';
            arr[index]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 1)
        {
            char ch = 'a' + i;
            cout << ch << " --> " << arr[i] << endl;
        }
    }
}
int main()
{
    string str = "test string";
    findCharacterCount(str);
}