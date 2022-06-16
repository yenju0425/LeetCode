#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        //convert s to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        //move alphabets and numbers foward
        string::iterator lastChar = remove_if(s.begin(), s.end(), [](char const &c){
            return !std::isalnum(c);
        });

        //palindrome checker
        for(string::iterator l = s.begin(), r = lastChar - 1; l <= r; l++, r--){
            if(*l != *r){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution *S = new Solution();

    string s = " ";

    cout << S->isPalindrome(s) << endl;

    return 0;
}