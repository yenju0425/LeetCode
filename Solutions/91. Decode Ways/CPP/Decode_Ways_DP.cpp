#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int s_len = s.length();

        if (s_len == 1) {
            return (s != "0");
        }

        vector<int> numOfWays(s_len, 0);
        numOfWays[0] = (s[0] != '0');
        numOfWays[1] = numOfWays[0] * (s[1] != '0') + (s[0] != '0' && stoi(s.substr(0, 2)) <= 26);

        for (int i = 2; i < s_len; ++i) {
            numOfWays[i] = numOfWays[i - 1] * (s[i] != '0') +
                           numOfWays[i - 2] * (s[i - 1] != '0' && (stoi(s.substr(i - 1, 2)) <= 26));
        }

        return numOfWays.back();
    }
};

int main() {
    Solution S;

    // input
    string s = "226";

    cout << S.numDecodings(s) << endl;

    return 0;
}
