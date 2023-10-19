#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
            }
        }

        return DP[m - 1][n - 1];
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int m = 23;
    int n = 12;

    cout << S->uniquePaths(m, n) << endl;

    return 0;
}
