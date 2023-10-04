#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        text1 = '\0' + text1;
        text2 = '\0' + text2;

        int length1 = text1.size();
        int length2 = text2.size();

        vector<vector<int>> LCS = vector<vector<int>>(length1, vector<int>(length2, 0));

        for (int i = 1; i < length1; ++i) {
            for (int j = 1; j < length2; ++j) {
                LCS[i][j] = (text1[i] == text2[j]) ? LCS[i - 1][j - 1] + 1 : max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }

        return LCS[length1 - 1][length2 - 1];
    }
};

int main(){
    Solution S;

    //input
    string text1 = "abcde";
    string text2 = "ace";

    cout << S.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
