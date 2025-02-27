#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int s_size = s.size();
        for (int i = 0, j = s_size - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }

    int removePalindromeSub(string s) {
        return isPalindrome(s)
                   ? 1
                   : 2;  // if s is not palindrome, remove all a's, and then remove all b's (at most 2 steps)
    }
};

int main() {
    Solution S;

    // input
    string s = "aababbb";

    cout << S.removePalindromeSub(s) << endl;

    return 0;
}
