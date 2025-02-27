#include <iostream>

using namespace std;

class Solution {
private:
    string s;
    string p;
    int s_size;
    int p_size;

public:
    bool isMatch(int si, int pi) {
        if (pi == p_size) {
            return si == s_size;
        }

        bool fistMatch = (si != s_size && (s[si] == p[pi] || p[pi] == '.'));
        if (pi + 1 != p_size && p[pi + 1] == '*') {  // next pi is '*'
            return isMatch(si, pi + 2) || (fistMatch && isMatch(si + 1, pi));
        } else {
            return (fistMatch && isMatch(si + 1, pi + 1));
        }
    }

    bool isMatch(string s, string p) {
        this->s      = s;
        this->p      = p;
        this->s_size = s.size();
        this->p_size = p.size();

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
