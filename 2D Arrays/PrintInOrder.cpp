#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printInSortedOrder(vector<vector<int>> matrix)
{

    vector<int> temp;

    int row = matrix.size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << temp[count] << " ";
            count++;
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> Mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    printInSortedOrder(Mat);
}