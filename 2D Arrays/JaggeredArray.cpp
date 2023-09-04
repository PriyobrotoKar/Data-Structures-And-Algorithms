#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;
    int *cols = new int[row];
    cout << "Enter the number of cols in each row:" << endl;
    for (int i = 0; i < row; i++)
    {
        cin >> cols[i];
    }
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[cols[i]];
    }
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    cout << "The elements of the array:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}