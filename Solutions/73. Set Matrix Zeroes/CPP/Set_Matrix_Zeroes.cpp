#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> zeros;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeros.push_back(vector<int>{i, j});
                }
            }
        }

        int numOfZeros = zeros.size();
        for (int i = 0; i < numOfZeros; ++i) {
            int row = zeros[i][0];
            int col = zeros[i][1];

            // reset col
            for (int j = 0; j < m; ++j) {
                matrix[j][col] = 0;
            }

            // reset row
            for (int j = 0; j < n; ++j) {
                matrix[row][j] = 0;
            }
        }
    }
};

int main() {
    Solution S;

    // input
    vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    S.setZeroes(matrix);

    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
