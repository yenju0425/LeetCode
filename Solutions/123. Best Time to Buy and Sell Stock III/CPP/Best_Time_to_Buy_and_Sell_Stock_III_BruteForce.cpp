#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int prices_size = prices.size();
        for (int i = 0; i < prices_size; i++) {
            // part A
            int buyPrice_A = prices[0];
            int profit_A   = 0;
            for (int j = 1; j <= i; j++) {
                if (prices[j] < buyPrice_A) {
                    buyPrice_A = prices[j];
                } else {
                    profit_A = max(profit_A, prices[j] - buyPrice_A);
                }
            }

            // part B
            int buyPrice_B = prices[i];
            int profit_B   = 0;
            for (int j = i + 1; j < prices_size; j++) {
                if (prices[j] < buyPrice_B) {
                    buyPrice_B = prices[j];
                } else {
                    profit_B = max(profit_B, prices[j] - buyPrice_B);
                }
            }

            profit = max(profit, profit_A + profit_B);
        }

        return profit;
    }
};

int main() {
    Solution S;

    // input
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};

    cout << S.maxProfit(prices) << endl;

    return 0;
}
