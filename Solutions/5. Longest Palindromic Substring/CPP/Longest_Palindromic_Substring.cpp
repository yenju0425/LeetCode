#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strigSize = s.size();

        // initialize
        int maxLength = 1;
        int left = 0;
        int right = 0;
        for (float i = 1.0; i < strigSize; i = i + 0.5) {
            int l = i - 0.5;
            int r = i;
            while (l >= 0 && r < strigSize && s[l] == s[r]) {
                l = l - 1;
                r = r + 1;
            }

            int length = r - l - 1;
            if (length > maxLength) {
                maxLength = length;
                left = l + 1;
                right = r - 1;
            }
        }

        return s.substr(left, maxLength);
    }
};

int main() {
    Solution S;

    // input
    string s = "eabcb";

    cout << S.longestPalindrome(s) << endl;

    return 0;
}
