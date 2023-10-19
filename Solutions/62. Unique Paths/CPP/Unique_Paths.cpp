#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        m = m - 1;
        n = n - 1;
        int steps = m + n;
        vector<unsigned long long> fact(steps + 1, 1);  // still overflow
        for (int i = 1; i <= steps; i++) {
            fact[i] = fact[i - 1] * i;
        }

        return fact[steps] / fact[m] / fact[n];
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int m = 23;
    int n = 12;

    cout << S->uniquePaths(m, n) << endl;

    return 0;
}
