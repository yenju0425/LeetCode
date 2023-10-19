#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charIdx(26);

        // record the idx of each char in s
        int s_len = s.length();
        for (int i = 0; i < s_len; i++) {
            charIdx[s[i] - 'a'].push_back(i);
        }

        int result = 0;

        int numOfWords = words.size();
        for (int i = 0; i < numOfWords; i++) {
            int s_idx = -1;
            bool isSQ = true;

            int w_len = words[i].length();
            for (int w_idx = 0; w_idx < w_len; w_idx++) {
                vector<int>::iterator iter = upper_bound(charIdx[words[i][w_idx] - 'a'].begin(), charIdx[words[i][w_idx] - 'a'].end(), s_idx);
                if (iter == charIdx[words[i][w_idx] - 'a'].end()) {
                    isSQ = false;
                    break;
                }

                s_idx = *iter;
            }

            result = result + isSQ;
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    string s = "abcde";
    vector<string> words{"a", "bb", "acd", "ace", "ae", "bd"};

    cout << S->numMatchingSubseq(s, words) << endl;

    return 0;
}
