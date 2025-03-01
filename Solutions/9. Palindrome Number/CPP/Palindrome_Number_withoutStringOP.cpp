// Reference: https://leetcode.com/problems/palindrome-number/solution
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverted_x = 0;
        while (x > reverted_x) {
            reverted_x = reverted_x * 10 + x % 10;
            x          = x / 10;
        }

        return (x == reverted_x) || (x == reverted_x / 10);  // ex: "12321" will cause x = 12, reverted_x = 123
    }
};

int main() {
    Solution S;

    // input
    int x = 12321;

    cout << S.isPalindrome(x) << endl;

    return 0;
}
