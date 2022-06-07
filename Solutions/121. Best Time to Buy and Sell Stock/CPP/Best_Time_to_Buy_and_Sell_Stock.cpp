#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int profitAfter_b = INT_MIN;
        int profitAfter_s = 0;
        
        //greedy algorithm
        int prices_size = prices.size();
        for (int i = 0; i < prices_size; i++){
            //look for the best buyTime and sellTime (from prices[0] ~ prices[i])
            profitAfter_b = max(profitAfter_b,               - prices[i]);
            profitAfter_s = max(profitAfter_s, profitAfter_b + prices[i]);
        }
        
        return profitAfter_s;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> prices{7, 1, 5, 3, 6, 4};

    cout << S->maxProfit(prices) << endl;

    return 0;
}