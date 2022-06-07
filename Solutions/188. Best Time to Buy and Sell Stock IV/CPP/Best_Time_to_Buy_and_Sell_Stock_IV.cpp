#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(int k, vector<int> &prices){
        vector<int> profitAfter_b(k + 1, INT_MIN);
        vector<int> profitAfter_s(k + 1, 0);

        //greedy algorithm
        int prices_size = prices.size();
        for(int i = 0; i < prices_size; i++){
            for(int j = 1; j <= k; j++){
                //iteratively look for the best buyTime[j] and sellTime[j] (from prices[0] ~ prices[i])
                profitAfter_b[j] = max(profitAfter_b[j], profitAfter_s[j - 1] - prices[i]);
                profitAfter_s[j] = max(profitAfter_s[j], profitAfter_b[j]     + prices[i]);
            }
        }

        return profitAfter_s[k];
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    int k = 2;
    vector<int> prices{3, 2, 6, 5, 0, 3};

    cout << S->maxProfit(k, prices) << endl;

    return 0;
}