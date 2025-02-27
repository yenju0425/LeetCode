#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int idx     = 0;
        int temp[2] = {cost[0], cost[1]};
        for (vector<int>::iterator iter = cost.begin() + 2; iter != cost.end(); iter++) {
            temp[idx] = min(temp[0], temp[1]) + *iter;
            idx       = !idx;
        }

        return min(temp[0], temp[1]);
    }
};

int main() {
    Solution S;

    // input
    vector<int> cost{10, 15, 20};

    cout << S.minCostClimbingStairs(cost) << endl;

    return 0;
}
