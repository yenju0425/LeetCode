#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> lookupTable;

public:
    int coinChange(vector<int>& coins, int amount){
        int numOfCoins = coins.size();

        lookupTable = vector<int>(amount + 1, -1);
        lookupTable[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < numOfCoins; j++){
                int index = i - coins[j];

                //if there is a way to exchange money, update lookupTable[i]
                if(index >= 0 and lookupTable[index] != -1){
                    if(lookupTable[i] == -1){
                        lookupTable[i] = lookupTable[index] + 1;
                    }
                    else{
                        lookupTable[i] = min(lookupTable[i], lookupTable[index] + 1);
                    }
                }
            }
        }
        return lookupTable[amount];
    }
};

int main(){
    Solution* S = new Solution();

    vector<int> coins{2};

    cout << S->coinChange(coins, 3) << endl;

    return 0;
}