#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int result = 1;

        int s_length = s.length();
        vector<int> lengthCounter(s_length, 1);

        // lengthCounter
        for (int i = 1; i < s_length; ++i) {
            int intervalWidth = i;
            bool isDone = true;
            for (int j = 0; j < s_length - intervalWidth; ++j) {
                if ((lengthCounter[j] == intervalWidth) && (lengthCounter[j + 1] == intervalWidth) && (s[j] != s[j + intervalWidth])) {
                    lengthCounter[j] = lengthCounter[j] + 1;
                    result = lengthCounter[j];
                    isDone = false;
                }
            }
            if (isDone) {  // no merge happened
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    string s = "aaabcdeababb";

    cout << S.lengthOfLongestSubstring(s) << endl;

    return 0;
}
