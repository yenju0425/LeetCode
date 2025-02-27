#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
    int M;
    int N;
    vector<vector<char>> matrix;
    map<vector<int>, int> dp;

public:
    int findMaxRectangle(vector<int> range) {
        if (range[2] - range[0] == 0 || range[3] - range[1] == 0) {
            return 0;
        }

        if (!dp.count(range)) {
            // init dp[range]
            dp[range]        = (range[2] - range[0]) * (range[3] - range[1]);
            bool isRectangle = true;

            // check every cell
            for (int i = range[0]; i < range[2] && isRectangle; ++i) {
                for (int j = range[1]; j < range[3] && isRectangle; ++j) {
                    if (matrix[i][j] == '0') {
                        isRectangle = false;

                        // divide and conquer
                        dp[range] = max(max(findMaxRectangle(vector<int>{range[0], range[1], range[2], j}),
                                            findMaxRectangle(vector<int>{range[0], range[1], i, range[3]})),
                                        max(findMaxRectangle(vector<int>{range[0], j + 1, range[2], range[3]}),
                                            findMaxRectangle(vector<int>{i + 1, range[1], range[2], range[3]})));
                    }
                }
            }
        }

        return dp[range];
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        this->M      = matrix.size();
        this->N      = matrix[0].size();
        this->matrix = matrix;

        vector<int> range{0, 0, M, N};  // from (0, 0) to (M, N)

        return findMaxRectangle(range);
    }
};

int main() {
    Solution S;

    // input
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    cout << S.maximalRectangle(matrix) << endl;

    return 0;
}
