#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool BS(int r_begin, int r_end, int c_begin, int c_end, vector<vector<int>>& M, int& T) {
        if (r_begin == r_end || c_begin == c_end) {
            return false;
        }

        int row = (r_begin + r_end) >> 1;
        int col = (c_begin + c_end) >> 1;

        if (M[row][col] < T) {
            return BS(row + 1, r_end, col + 1, c_end, M, T) || BS(row + 1, r_end, c_begin, col + 1, M, T) ||
                   BS(r_begin, row + 1, col + 1, c_end, M, T);
        } else if (M[row][col] > T) {
            return BS(r_begin, row, c_begin, col, M, T) || BS(r_begin, row, col, c_end, M, T) ||
                   BS(row, r_end, c_begin, col, M, T);
        }

        return true;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int& target) {
        return BS(0, matrix.size(), 0, matrix[0].size(), matrix, target);
    }
};

int main() {
    Solution S;

    int target = 7;
    vector<vector<int>> matrix{{1, 4, 7}};

    cout << S.searchMatrix(matrix, target) << endl;

    return 0;
}
