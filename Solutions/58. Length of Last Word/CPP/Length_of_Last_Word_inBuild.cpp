#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string::iterator r = s.end() - 1;
        
        while(*r == ' ') {
            r = r - 1;
        }

        string::iterator l = r - 1;
        while(*l != ' ' && l - s.begin() >= 0) {
            l  = l  - 1;
        }
        
        return r - l;
    }
};

int main() {
    Solution S;

    string s = "a";

    cout << S.lengthOfLastWord(s) << endl;
    
    return 0;
}
