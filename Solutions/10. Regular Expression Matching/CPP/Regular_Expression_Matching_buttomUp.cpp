#include <iostream>

using namespace std;

class Solution{
private:
    string s = "";
    string p = "";
    int s_size = 0;
    int p_size = 0;

public:
    bool isMatch(string s, string p){
        this->s = s;
        this->p = p;
        this->s_size = s.size();
        this->p_size = p.size();

        return isMatch(0, 0);
    }
    bool isMatch(int si, int pi){
        if(pi == p_size){
            return si == s_size;
        }

        bool fistMatch = (si != s_size and (s[si] == p[pi] or p[pi] == '.'));
        if(pi + 1 != p_size and p[pi + 1] == '*'){ //next pi is '*'
            return isMatch(si, pi + 2) or (fistMatch and isMatch(si + 1, pi));
        }
        else{
            return (fistMatch and isMatch(si + 1, pi + 1));
        }
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    string s = "c";
    string p = "c*";

    cout << S->isMatch(s, p) << endl;

    return 0;
}
