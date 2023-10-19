#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int maximum = 0;
        int summation = 0;

        int amount_size = amount.size();
        for (int i = 0; i < amount_size; i++) {
            maximum = max(maximum, amount[i]);
            summation = summation + amount[i];
        }

        return max(maximum, (summation + 1) / 2);
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> amount{4, 5, 4, 3};

    cout << S->fillCups(amount) << endl;

    return 0;
}
