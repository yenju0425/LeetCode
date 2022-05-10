#include <iostream>

using namespace std;

class Solution {
private:
    string s = "";
    string p = "";
    int s_size = 0;
    int p_size = 0;

public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->s_size = s.size();
        this->p_size = p.size();

        return isMatch(0, 0);
    }
    bool isMatch(int si, int pi) {
        if(si == s_size and pi == p_size){
            return true;
        }
        else if(pi == p_size){ //if pi goes to final state
            return false;
        }
        else if(pi + 1 != p_size and p[pi + 1] == '*'){ //next pi is '*'
            if(isMatch(si, pi + 2)){
                return true;
            }
            else if(si != s_size and (s[si] == p[pi] or p[pi] == '.')){
                return isMatch(si + 1, pi);
            }
            else{
                return false;
            }
        }
        else if(si != s_size and (s[si] == p[pi] or p[pi] == '.')){
            return isMatch(si + 1, pi + 1);
        }
        return false;
    }
};

int main(){
    Solution *S = new Solution();

    cout << S->isMatch("c", "c*") << endl;

    return 0;
}
