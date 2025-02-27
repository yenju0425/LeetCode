#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string s;
    string p;
    int s_size;
    int p_size;
    vector<vector<int>> DP;

public:
    bool isMatch(int si, int pi) {
        if (DP[si][pi] != -1) {  // check the DP table first
            return DP[si][pi];
        }

        bool match;
        if (pi == p_size) {
            match = (si == s_size);
        } else {
            bool fistMatch = (si != s_size) && (s[si] == p[pi] || p[pi] == '.');
            if (p[pi + 1] == '*') {  // next pi is '*'
                match = isMatch(si, pi + 2) || (fistMatch && isMatch(si + 1, pi));
            } else {
                match = fistMatch && isMatch(si + 1, pi + 1);
            }
        }

        DP[si][pi] = match;

        return match;
    }

    bool isMatch(string s, string p) {
        this->s_size = s.size();
        this->p_size = p.size();
        this->s      = s + "&";
        this->p      = p + "&";
        this->DP     = vector<vector<int>>(s_size + 1, vector<int>(p_size + 1, -1));

        return isMatch(0, 0);
    }
};

int main() {
    Solution S;

    string s = "ab";
    string p = ".*";

    cout << S.isMatch(s, p) << endl;

    return 0;
}
