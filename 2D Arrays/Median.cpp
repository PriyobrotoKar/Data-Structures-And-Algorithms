#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C)
{
    vector<int> temp;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[temp.size() / 2];
}

int main()
{
    vector<vector<int>> Mat = {{1, 3, 5},
                               {2, 6, 9},
                               {3, 6, 9}};
    cout << median(Mat, Mat.size(), Mat[0].size()) << endl;
}