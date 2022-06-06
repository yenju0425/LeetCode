#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int buyPrice = prices[0];
        int profit = 0;

        int prices_size = prices.size();
        for(int i = 1; i < prices_size; i++){
            int price = prices[i];
            
            //buy at a lower price
            if(buyPrice > price){
                buyPrice = price;
            }

            profit = max(profit, price - buyPrice);
        }

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