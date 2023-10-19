#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        vector<int> nums(n + 1, 0);
        nums[1] = 1;

        for (int i = 2; i <= n; i++) {
            nums[i] = nums[i - 2] + nums[i - 1];
        }

        return nums[n];
    }
};

int main() {
    Solution* S = new Solution();

    // input
    int n = 5;

    cout << S->fib(n) << endl;

    return 0;
}
