#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int profitAfter_b1 = INT_MIN;
        int profitAfter_s1 = 0;
        int profitAfter_b2 = INT_MIN;
        int profitAfter_s2 = 0;
        
        //greedy algorithm
        int prices_size = prices.size();
        for (int i = 0; i < prices_size; i++){
            //look for the best buyTime and sellTime (from prices[0] ~ prices[i])
            profitAfter_b1 = max(profitAfter_b1,                - prices[i]);
            profitAfter_s1 = max(profitAfter_s1, profitAfter_b1 + prices[i]);

            //look for another buyTime and sellTime, after finalize the first transaction (from prices[k] ~ prices[i], suppose the first sellTime is at k)
            profitAfter_b2 = max(profitAfter_b2, profitAfter_s1 - prices[i]);
            profitAfter_s2 = max(profitAfter_s2, profitAfter_b2 + prices[i]);
        }
        
        return profitAfter_s2;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};

    cout << S->maxProfit(prices) << endl;

    return 0;
}