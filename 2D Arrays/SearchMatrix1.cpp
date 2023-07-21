#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int start = 0;
    int end = (rows * cols) - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int midRow = mid / cols;
        int midCol = mid % cols;
        if (matrix[midRow][midCol] == target)
        {
            return true;
        }
        else if (matrix[midRow][midCol] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
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