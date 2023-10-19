#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());

        stringstream ss(s);

        ss >> s;  // reuse s

        return s.size();
    }
};

int main() {
    Solution S;

    string s = "   fly me   to   the moon  ";

    cout << S.lengthOfLastWord(s) << endl;

    return 0;
}
