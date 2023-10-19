#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string s = "";
    string p = "";
    int s_size = 0;
    int p_size = 0;
    vector<vector<int>> DP;

public:
    bool isMatch(string s, string p) {
        int s_length = s.length();
        int p_length = p.length();

        s = s + "&";  //'&' is the "end of string" char
        p = p + "&";

        vector<vector<bool>> DP(s_length + 1, vector<bool>(p_length + 1, false));
        // init DP[s_length][p_length]
        DP[s_length][p_length] = true;

        // init last row
        for (int i = p_length - 1; i >= 0; --i) {
            if (p[i + 1] == '*') {
                DP[s_length][i] = DP[s_length][i + 2];
            }
        }

        for (int i = s_length - 1; i >= 0; --i) {
            for (int j = p_length - 1; j >= 0; --j) {
                switch (p[j + 1]) {
                    case '*':
                        DP[i][j] = ((s[i] == p[j] || p[j] == '.') && DP[i + 1][j]) || DP[i][j + 2];
                        break;

                    default:
                        DP[i][j] = ((s[i] == p[j] || p[j] == '.') && DP[i + 1][j + 1]);
                }
            }
        }

        return DP[0][0];
    }
};

int main() {
    Solution S;

    // inputs
    string s = "ab";
    string p = ".*";

    cout << S.isMatch(s, p) << endl;

    return 0;
}
