#include <iostream>

using namespace std;

class Solution {
private:
    string s;
    int s_len;
    int numOfWays;

public:
    void countWays(int idx) {
        if (idx == s_len) {
            numOfWays = numOfWays + 1;
            return;
        }

        if (s[idx] == '0') {
            return;
        }

        // take 1
        countWays(idx + 1);

        // take 2
        if (idx < s_len - 1 && stoi(s.substr(idx, 2)) <= 26) {
            countWays(idx + 2);
        }
    }

    int numDecodings(string s) {
        this->s = s;
        this->s_len = s.length();
        this->numOfWays = 0;

        countWays(0);

        return numOfWays;
    }
};

int main() {
    Solution S;

    // input
    string s = "226";

    cout << S.numDecodings(s) << endl;

    return 0;
}
