#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // catalan number
        double c = 1;

        for (int i = 1, j = 2 * n; i <= n; i++, j--) {
            c = c * j;
            c = c / i;
        }

        return c / (n + 1);
    }
};

int main() {
    Solution* S = new Solution();

    // input
    int n = 3;

    cout << S->numTrees(n) << endl;

    return 0;
}
