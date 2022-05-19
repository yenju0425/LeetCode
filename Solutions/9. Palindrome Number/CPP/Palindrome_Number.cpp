#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        string s  = to_string(x);
        int stringLength = s.length();

        for(int i = 0; i < stringLength/2; i++){
            if(s[i] != s[stringLength - 1 - i]){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->isPalindrome(12321) << endl;

    return 0;
}