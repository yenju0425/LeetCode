#include <iostream>
#include <vector>

using namespace std;

class NumMatrix{
private:
    vector<vector<int>> M;
    int m;
    int n;

public:
    NumMatrix(vector<vector<int>> &matrix){
        M = matrix;
        m = matrix.size();
        n = matrix[0].size();

        //re-use "matrix" to store summation from (0, 0) to (i, j)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int a = readMatrix(i - 1, j    );
                int b = readMatrix(i    , j - 1);
                int c = readMatrix(i - 1, j - 1);

                M[i][j] = M[i][j] + a + b - c;
            }
        }
    }

    int readMatrix(int i, int j){
        return (i >= 0 and j >= 0) ? M[i][j] : 0; //check up border and right border
    }
    
    int sumRegion(int row1, int col1, int row2, int col2){
        int a = readMatrix(row1 - 1, col2    );
        int b = readMatrix(row2    , col1 - 1);
        int c = readMatrix(row1 - 1, col1 - 1);

        return M[row2][col2] - a - b + c;
    }
};

int main(){
    vector<vector<int>> matrix{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix* N = new NumMatrix(matrix);

    cout << N->sumRegion(2, 1, 4, 3) << endl; // return 8
    cout << N->sumRegion(1, 1, 2, 2) << endl; // return 11
    cout << N->sumRegion(1, 2, 2, 4) << endl; // return 12

    return 0;
}