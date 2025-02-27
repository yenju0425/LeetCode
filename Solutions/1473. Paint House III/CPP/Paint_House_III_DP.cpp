#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m;
    int n;
    int target;
    vector<vector<vector<int>>> dp;

public:
    int paint(vector<int>& houses, vector<vector<int>>& cost, int idx, int preColor, int numOfNbh) {
        unsigned int result = INT_MAX;

        // out of border
        if (numOfNbh > target) {
            return result;
        }
        if (idx >= m) {
            return (numOfNbh == target) ? 0 : result;
        }

        // if the cost is not cached
        if (!dp[idx][preColor][numOfNbh]) {
            int curColor = houses[idx];
            if (curColor == 0) {
                for (int i = 1; i <= n; i++) {
                    houses[idx] = i;
                    result      = min(result, unsigned(cost[idx][i - 1]) +
                                                  paint(houses, cost, idx + 1, i, numOfNbh + (i != preColor)));
                }
                houses[idx]                 = 0;
                dp[idx][preColor][numOfNbh] = result;
            } else {
                dp[idx][preColor][numOfNbh] = paint(houses, cost, idx + 1, curColor, numOfNbh + (curColor != preColor));
            }
        }
        return dp[idx][preColor][numOfNbh];
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m      = m;
        this->n      = n;
        this->target = target;
        this->dp     = vector<vector<vector<int>>>(m, vector<vector<int>>(n + 1, vector<int>(target + 1, 0)));

        int result = paint(houses, cost, 0, 0, 0);

        return (result >= INT_MAX) ? -1 : result;
    }
};

int main() {
    Solution S;

    int m      = 5;
    int n      = 2;
    int target = 3;
    vector<int> houses{0, 0, 0, 0, 0};
    vector<vector<int>> cost{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};

    cout << S.minCost(houses, cost, m, n, target) << endl;

    return 0;
}
