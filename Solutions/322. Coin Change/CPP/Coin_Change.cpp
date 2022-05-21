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
            int temp = -1;
            for(int j = 0; j < numOfCoins; j++){
                int index = i - coins[j];
                if(index >= 0 and lookupTable[index] != -1){
                    if(temp == -1 or temp > lookupTable[index] + 1){
                        temp = lookupTable[index] + 1;
                    }
                }
            }
            lookupTable[i] = temp;
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