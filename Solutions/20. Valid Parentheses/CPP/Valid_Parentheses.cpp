#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> S;
        for(string::iterator c = s.begin(); c != s.end(); c = c + 1){
            if(*c == '(' or *c == '[' or *c == '{'){
                S.push(*c);
            }
            else if(*c == ')'){
                if(S.empty() or S.top() != '('){
                    return false;
                }
                S.pop();
            }
            else if(*c == ']'){
                if(S.empty() or S.top() != '['){
                    return false;
                }
                S.pop();
            }
            else if(*c == '}'){
                if(S.empty() or S.top() != '{'){
                    return false;
                }
                S.pop();
            }
            else{
                return false;
            }
        }
        if(!S.empty()){
            return false;
        }
        return true;
    }
};

int main(){
    Solution *S = new Solution();
    cout << S->isValid("([)]") << endl;
    return 0;
}