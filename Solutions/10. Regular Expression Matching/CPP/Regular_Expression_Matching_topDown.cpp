#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    string s;
    string p;
    int s_size;
    int p_size;
    vector<vector<int>> DP;

public:
    bool isMatch(int si, int pi){
        if(DP[si][pi] != -1){ //check the DP table first
            return bool(DP[si][pi]);
        }

        bool match;
        if(pi == p_size){
            match = (si == s_size);
        }
        else{
            bool fistMatch = (si != s_size) and (s[si] == p[pi] or p[pi] == '.');
            if(pi + 1 != p_size and p[pi + 1] == '*'){ //next pi is '*'
                match = isMatch(si, pi + 2) or (fistMatch and isMatch(si + 1, pi));
            }
            else{
                match = fistMatch and isMatch(si + 1, pi + 1);
            }
        }
    
        DP[si][pi] = match;
    
        return match;
    }
    
    bool isMatch(string s, string p){
        this->s = s;
        this->p = p;
        this->s_size = s.size();
        this->p_size = p.size();
        this->DP = vector<vector<int>>(s_size + 1, vector<int>(p_size + 1, -1));
    
        return isMatch(0, 0);
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    string s = "ab";
    string p = ".*";

    cout << S->isMatch(s, p) << endl;

    return 0;
}