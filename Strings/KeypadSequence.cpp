#include <iostream>
using namespace std;

void storeSequences(int arr[26])
{
    int index = 0;
    for (int i = 2; i < 10; i++)
    {
        for (int upper = (i == 7 || i == 9) ? 4 : 3, j = 0; j < upper; j++)
        {
            if (j == 0)
            {

                arr[index] = i;
                index++;
            }
            else
            {
                arr[index] = i + 10 * arr[index - 1];
                index++;
            }
        }
    }
}

string generateKeypadSequence(string wrd, int arr[26])
{
    string ans = "";
    for (int i = 0; i < wrd.length(); i++)
    {
        char ch = wrd[i];
        ans = ans + to_string(arr[ch - 'A']);
    }
    return ans;
}

int main()
{
    int seqarr[26];
    storeSequences(seqarr);
    string word;
    cout << "Enter a word:";
    cin >> word;
    string keypadSequence = generateKeypadSequence(word, seqarr);
    cout << keypadSequence << endl;
}