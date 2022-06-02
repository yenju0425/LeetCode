#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        n = n + 1; //in order to apply the Fibonacci closed-form expression
        double x = sqrt(5);
        return int((1 / x) * (pow((1 + x)/2, n) - pow((1 - x)/2, n)) + 0.5);
    }
};

int main(){
    Solution* S = new Solution();

    //input
    int n = 45;

    cout << S->climbStairs(n) << endl;

    return 0;
}