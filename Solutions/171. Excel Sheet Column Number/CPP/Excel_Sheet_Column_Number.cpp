#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (string::iterator iter = columnTitle.begin(); iter != columnTitle.end(); iter++) {
            result = result * 26 + *iter - '@';
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    string columnTitle = "AAA";

    cout << S->titleToNumber(columnTitle) << endl;

    return 0;
}
