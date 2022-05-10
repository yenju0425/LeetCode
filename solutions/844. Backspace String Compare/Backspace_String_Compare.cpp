#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t){
        string new_s = "";
        for(string::iterator i = s.begin(); i != s.end(); i++){
            if(*i != '#'){
                new_s.push_back(*i);
            }
            else if(!new_s.empty()){
                new_s.pop_back();
            }
        }

        string new_t = "";
        for(string::iterator i = t.begin(); i != t.end(); i++){
            if(*i != '#'){
                new_t.push_back(*i);
            }
            else if(!new_t.empty()){
                new_t.pop_back();
            }
        }

        return (new_s == new_t);
    }
};

int main(){
    Solution* S = new Solution();

    string s = "a##bc#d";
    string t = "dd##bx#d";

    cout << S->backspaceCompare(s, t) << endl;

    return 0;
}