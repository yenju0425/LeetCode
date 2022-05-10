#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
        string s  = to_string(x);
        string _s = "";

        int stringLength = s.length();

        for(int i = 0; i < stringLength; i++){
            _s.push_back(s[stringLength - 1 - i]);
        }

        return (s == _s);
    }
};

int main(){
    Solution *S = new Solution;
    cout << S->isPalindrome(-121) << endl;
    return 0;
}