#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        int charCount[26] = {0};

        int s_len = s1.length();
        for (int i = 0; i < s_len; ++i) {
            charCount[s1[i] - 'a']++;
            charCount[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (charCount[i] != 0) {
                return false;
            }
        }

        // speed up
        if (s_len <= 3) {
            return true;
        }

        for (int i = 1; i < s_len; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s_len - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s_len - i))) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution S;

    string s1 = "great";
    string s2 = "gtaer";

    cout << S.isScramble(s1, s2) << endl;

    return 0;
}
