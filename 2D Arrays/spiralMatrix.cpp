#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows= matrix.size();
        int cols= matrix[0].size();

        int startingRow=0;
        int startingCol=0;
        int endingRow=rows-1;
        int endingCol=cols-1;

        int count=0;
        int total=rows*cols;

        while(count < total){
            for(int index=startingCol;count < total && index<=endingCol;index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for(int index=startingRow;count < total && index<=endingRow;index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            for(int index=endingCol;count < total && index>=startingCol;index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for(int index=endingRow;count < total && index>=startingRow;index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
        
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
    vector<int> ansarr = spiralOrder(ar);
    for (int i = 0; i < ansarr.size(); i++)
    {
        cout << ansarr[i] << " ";
    }
}