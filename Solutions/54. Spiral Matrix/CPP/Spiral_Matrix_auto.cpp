#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // border[0]: min_row
    // border[1]: max_col
    // border[2]: max_row
    // border[3]: min_col

    int border[4];

public:
    bool isValid(int r, int c) { return (border[0] <= r && r < border[2] && border[3] <= c && c < border[1]); }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        border[0] = 0;
        border[1] = matrix[0].size();
        border[2] = matrix.size();
        border[3] = 0;

        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> result;

        int matrixSize = border[1] * border[2];
        for (int i = 0, r = 0, c = 0, d = 0; i < matrixSize; ++i) {
            result.push_back(matrix[r][c]);

            // look for next element
            int next_r = r + direction[d][0];
            int next_c = c + direction[d][1];
            if (isValid(next_r, next_c)) {
                r = next_r;
                c = next_c;
            } else {
                // update border, d
                int next_d = (d + 1) % 4;
                border[d]  = border[d] + direction[next_d][0] + direction[next_d][1];  // magic

                d = next_d;  // rotate direction clockwise must be a valid move
                r = r + direction[d][0];
                c = c + direction[d][1];
            }
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {9, 0, 1, 2}};

    vector<int> result = S.spiralOrder(matrix);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
