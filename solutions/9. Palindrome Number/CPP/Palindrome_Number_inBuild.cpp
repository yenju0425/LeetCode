#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
        string original = to_string(x);
        string reversed = original;

        reverse(reversed.begin(), reversed.end());

        return (original == reversed);
    }
};

int main(){
    Solution *S = new Solution;
    cout << S->isPalindrome(9487) << endl;
    return 0;
}