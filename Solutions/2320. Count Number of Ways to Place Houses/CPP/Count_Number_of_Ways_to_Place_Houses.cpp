#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        vector<unsigned long long> placement(n + 1);
        placement[0] = 1;
        placement[1] = 2;
        for (int i = 2; i <= n; i++) {
            placement[i] = (placement[i - 1] + placement[i - 2]) % 1000000007;
        }

        return (placement[n] * placement[n]) % 1000000007;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    int n = 1000;

    cout << S->countHousePlacements(n) << endl;

    return 0;
}
