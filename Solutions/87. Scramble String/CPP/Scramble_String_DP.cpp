#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2) {
        string key = s1 + "|" + s2;
        if (dp.count(key)) {
            return dp[key];
        }

        if (s1 == s2) {
            return true;
        }

        int charCount[26] = {0};

        int size = s1.length();
        for (int i = 0; i < size; ++i) {
            charCount[s1[i] - 'a']++;
            charCount[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (charCount[i] != 0) {
                return false;
            }
        }

        // speed up
        if (size <= 3) {
            return true;
        }

        dp[key] = false;
        for (int i = 1; i < size && !dp[key]; ++i) {
            dp[key] =
                (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(size - i)) && isScramble(s1.substr(i), s2.substr(0, size - i)));
        }

        return dp[key];
    }
};

int main() {
    Solution S;

    string s1 = "great";
    string s2 = "gtaer";

    cout << S.isScramble(s1, s2) << endl;

    return 0;
}
