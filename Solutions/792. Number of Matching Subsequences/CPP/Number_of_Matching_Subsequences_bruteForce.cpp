#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;

        int numOfWords = words.size();
        for (int i = 0; i < numOfWords; i++) {
            int idx = 0;
            int len = words[i].length();
            for (string::iterator c = s.begin(); c != s.end() && idx < len; c++) {
                idx = idx + (words[i][idx] == *c);
            }

            result = result + (idx == len);
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
