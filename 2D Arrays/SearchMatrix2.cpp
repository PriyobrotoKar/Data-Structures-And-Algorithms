#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            colIndex--;
        }
        else
        {
            rowIndex++;
        }
    }
    return false;
}
int main()
{
    int r, c, x;
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
    cout << "Enter the no. to be searched:";
    cin >> x;
    if (searchMatrix(ar, x))
    {
        cout << x << " is found in the matrix" << endl;
    }
    else
    {
        cout << x << " is not found in the matrix" << endl;
    }
}