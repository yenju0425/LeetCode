#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int s_size = s.size();
        vector<string> S;
        for(int i = 0; i < s_size; i++){
            char c = s[i];
            if(S.empty() or S.back()[0] != c){
                string newChar(1, c);
                S.push_back(newChar);
            }
            else{
                S.back().push_back(c);
                if(S.back().size() == k){
                    S.pop_back();
                }
            }
        }
        string s_removed = "";
        for(vector<string>::iterator i = S.begin(); i != S.end(); i++){
            s_removed = s_removed + *i;
        }
        return s_removed;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->removeDuplicates("deeedbbcccbda", 3) << endl;
    return 0;
}