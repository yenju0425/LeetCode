#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    int M;
    int N;
    vector<vector<int>> mat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->M = matrix.size();
        this->N = matrix[0].size();
        this->mat = matrix;

        // re-use "matrix" to store the summation from (0, 0) to (i, j)
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = mat[i][j] + readMatrix(i - 1, j) + readMatrix(i, j - 1) - readMatrix(i - 1, j - 1);
            }
        }
    }

    int readMatrix(int m, int n) {
        return (m >= 0 and n >= 0) ? mat[m][n] : 0;  // check up border and right border
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2][col2] - readMatrix(row1 - 1, col2) - readMatrix(row2, col1 - 1) + readMatrix(row1 - 1, col1 - 1);
    }
};

int main() {
    // input
    vector<vector<int>> matrix{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix* N = new NumMatrix(matrix);

    cout << N->sumRegion(2, 1, 4, 3) << endl;  // return 8
    cout << N->sumRegion(1, 1, 2, 2) << endl;  // return 11
    cout << N->sumRegion(1, 2, 2, 4) << endl;  // return 12

    return 0;
}
