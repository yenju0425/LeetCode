#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        n        = n + 1;  // in order to apply the Fibonacci closed-form expression
        double x = sqrt(5);
        return int((1 / x) * (pow((1 + x) / 2, n) - pow((1 - x) / 2, n)) + 0.5);  // 0.5: round double
    }
};

int main() {
    Solution S;

    // input
    int n = 45;

    cout << S.climbStairs(n) << endl;

    return 0;
}
