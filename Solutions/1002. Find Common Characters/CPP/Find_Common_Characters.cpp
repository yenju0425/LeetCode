#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words){
        vector<string> CC(0, ""); //the vector to store the common chars
        vector<int> charCounter(26, numeric_limits<int>::max());
        for(vector<string>::iterator i = words.begin(); i != words.end(); i++){
            vector<int> temp(26, 0);
            for(string::iterator c = i->begin(); c != i->end(); c++){
                int charIndex = *c - 'a';
                temp[charIndex] = temp[charIndex] + 1;
            }
            for(int j = 0; j < 26; j++){
                charCounter[j] = min(charCounter[j], temp[j]);
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < charCounter[i]; j++){
                string s;
                s.push_back(char('a' + i));
                CC.push_back(s);
            }
        }
        return CC;
    }
};

int main(){
    vector<string> voc = {"bella","label","roller"};
    Solution* S = new Solution;
    vector<string> ans = S->commonChars(voc);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}