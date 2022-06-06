#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int profit = 0;

        int buyPrice  = prices[0];
        int sellPrice = prices[0];

        int prices_size = prices.size();
        for(int i = 1; i < prices_size; i++){
            int price = prices[i];

            //accumulate profit
            if(price < sellPrice){
                profit = profit + sellPrice - buyPrice;

                //update buyPrice and sellPrice
                buyPrice  = price;
                sellPrice = price;
            }
            else{
                sellPrice = max(sellPrice, price);
            }
        }

        profit = profit + sellPrice - buyPrice;

        return profit;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> prices{7, 1, 5, 3, 6, 4};

    cout << S->maxProfit(prices) << endl;

    return 0;
}