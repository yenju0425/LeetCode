#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> houses;
    vector<vector<int>> cost;
    int m;
    int n;
    int target;
    int minC;

public:
    void paint(int idx, int preColor, int numOfNbh, int C) {
        if (idx == m) {
            if (numOfNbh == target) {
                minC = min(minC, C);
            }
            return;
        }

        if (numOfNbh <= target) {
            int curColor = houses[idx];
            if (curColor == 0) {
                for (int i = 1; i <= n; i++) {
                    houses[idx] = i;
                    paint(idx + 1, i, numOfNbh + (i != preColor), C + cost[idx][i - 1]);
                }
                houses[idx] = 0;
            } else {
                paint(idx + 1, curColor, numOfNbh + (curColor != preColor), C);
            }
        }
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->houses = houses;
        this->cost   = cost;
        this->m      = m;
        this->n      = n;
        this->target = target;
        this->minC   = INT_MAX;

        paint(0, 0, 0, 0);

        return (minC == INT_MAX) ? -1 : minC;
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
