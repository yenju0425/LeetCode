#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i and j <= k; j++) {
                dp[i][j] = (0UL + dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
            }
            for (int j = i; j <= k; j++) {
                dp[i][j] = (0UL + dp[i][j - 1] + dp[i - 1][j] + 1000000007 - dp[i - 1][j - i]) % 1000000007;
            }
        }

        return dp[n][k];
    }
};

int main() {
    Solution S;

    int n = 3;
    int k = 1;

    cout << S.kInversePairs(n, k) << endl;

    return 0;
}
