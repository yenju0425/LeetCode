#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();

        // init charCounter
        int charCounter[58] = {0};  //'z' - 'A' + 1 = 58
        for (int i = 0; i < t_length; ++i) {
            int idx = t[i] - 'A';
            charCounter[idx] = charCounter[idx] + 1;
        }

        int minString_pos = 0;
        int minString_len = INT_MAX;

        // iterate through s
        for (int left = 0, right = 0; right < s_length; ++right) {
            int right_idx = s[right] - 'A';
            charCounter[right_idx] = charCounter[right_idx] - 1;
            t_length = (charCounter[right_idx] < 0) ? t_length : t_length - 1;

            while (t_length == 0) {
                if (right - left + 1 < minString_len) {
                    minString_pos = left;
                    minString_len = right - left + 1;
                }

                // remove left
                int left_idx = s[left] - 'A';
                charCounter[left_idx] = charCounter[left_idx] + 1;
                t_length = (charCounter[left_idx] > 0) ? t_length + 1 : t_length;

                left = left + 1;
            }
        }

        return minString_len == INT_MAX ? "" : s.substr(minString_pos, minString_len);
    }
};

int main() {
    Solution S;

    // inputs
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << S.minWindow(s, t) << endl;

    return 0;
}
