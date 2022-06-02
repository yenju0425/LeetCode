#include <iostream>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        int* numOfWays = new int[n + 1]{0};
        numOfWays[0] = 1;
        numOfWays[1] = 1;
        for(int i = 2; i <= n; i++){
            numOfWays[i] = numOfWays[i - 1] + numOfWays[i - 2];
        }

        return numOfWays[n];
    }
};

int main(){
    Solution* S = new Solution();
    
    //input
    int n = 45;

    cout << S->climbStairs(n) << endl;

    return 0;
}