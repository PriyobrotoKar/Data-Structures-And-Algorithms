#include <iostream>
using namespace std;

int runCustomerSimulation(int n, string seq)
{
    int ans = 0;
    n = n - 2;
    for (int i = 1; i < seq.length(); i++)
    {
        char ch = seq[i];
        int f = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (ch == seq[j]) //* checking if the current character matches any previous character
            {
                n++; // increasing the number of available computers
                f = 1;

                if (n < 0)
                {
                    ans++;
                }
                break;
            }
        }
        if (!f)
        {
            n--; // decreasing the number of available computers
        }
    }
    return ans;
}

int main()
{
    int n;
    string seq;
    cout << "Enter the number of computers:";
    cin >> n;
    cout << "Enter the customer sequence:";
    cin >> seq;
    cout << "The number of customers walked away: " << runCustomerSimulation(n, seq) << endl;
}