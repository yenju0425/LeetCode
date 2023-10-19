#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_length = word1.length();
        int word2_length = word2.length();

        word1 = "$" + word1;  //'$' is the "begin of string" char
        word2 = "$" + word2;

        vector<vector<int>> DP(word1_length + 1, vector<int>(word2_length + 1, 0));

        for (int i = 1; i <= word1_length; i++) {
            for (int j = 1; j <= word2_length; j++) {
                if (word1[i] == word2[j]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                }
                else {
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                }
            }
        }

        return word1_length + word2_length - 2 * DP[word1_length][word2_length];
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    string word1 = "Richard";
    string word2 = "Lillard";

    cout << S->minDistance(word1, word2) << endl;

    return 0;
}
