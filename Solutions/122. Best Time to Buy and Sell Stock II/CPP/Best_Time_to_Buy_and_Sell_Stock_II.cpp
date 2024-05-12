#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int current_buy = numeric_limits<int>::max();
        for (const auto& p : prices) {
            profit += max(0, p - current_buy);
            current_buy = p;
        }

        return profit;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> prices{7, 1, 5, 3, 6, 4};

    cout << S->maxProfit(prices) << endl;

    return 0;
}
