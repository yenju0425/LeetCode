#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string removeDuplicates(string s, int k){
        vector<string> S;

        int s_size = s.length();
        for(int i = 0; i < s_size; i++){
            char c = s[i];
            if(S.empty() || S.back()[0] != c){
                string newChar(1, c);
                S.push_back(newChar);
            }
            else{
                S.back().push_back(c);
                if(S.back().length() == k){
                    S.pop_back();
                }
            }
        }

        string s_removed;
        for(vector<string>::iterator i = S.begin(); i != S.end(); i++){
            s_removed = s_removed + *i;
        }

        return s_removed;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 3;
    string s = "deeedbbcccbda";

    cout << S->removeDuplicates(s, k) << endl;

    return 0;
}