#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int rows = matrix.size();

    for (int i = 0; i < rows; i++)
    {

        for (int j = i; j < rows; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    int r, c;
    cout << "Enter the no. of rows:";
    cin >> r;
    cout << "Enter the no. of columns:";
    cin >> c;
    cout << "Enter the elements:" << endl;
    vector<vector<int>> ar(r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int temp;
            cin >> temp;
            ar[i].push_back(temp);
        }
    }
    rotate(ar);
    for (int i = 0; i < ar.size(); i++)
    {
        for (int j = 0; j < ar[0].size(); j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}