#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost_size = cost.size();
        for (int i = 2; i < cost_size; i++) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[cost_size - 1], cost[cost_size - 2]);
    }
};

int main() {
    Solution S;

    // input
    vector<int> cost{10, 15, 20};

    cout << S.minCostClimbingStairs(cost) << endl;

    return 0;
}
