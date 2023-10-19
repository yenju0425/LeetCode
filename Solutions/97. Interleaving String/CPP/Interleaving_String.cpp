#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string s1;
    string s2;
    string s3;
    int s1_length;
    int s2_length;
    int s3_length;
    vector<vector<int>> DP;

public:
    bool IL(int i1, int i2, int i3) {
        if (i3 == s3_length) {
            return true;
        }

        if (i1 <= s1_length and i2 <= s2_length and DP[i1][i2] != -1) {
            return DP[i1][i2];
        }

        DP[i1][i2] = (i1 < s1_length and s1[i1] == s3[i3] and IL(i1 + 1, i2, i3 + 1)) or (i2 < s2_length and s2[i2] == s3[i3] and IL(i1, i2 + 1, i3 + 1));
        return DP[i1][i2];
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->s1_length = s1.length();
        this->s2_length = s2.length();
        this->s3_length = s3.length();

        this->DP = vector<vector<int>>(s1_length + 1, vector<int>(s2_length + 1, -1));

        if (s1_length + s2_length != s3_length) {
            return false;
        }

        return IL(0, 0, 0);
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    cout << S->isInterleave(s1, s2, s3) << endl;

    return 0;
}
