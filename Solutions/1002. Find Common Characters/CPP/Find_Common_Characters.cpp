#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> commonChars(vector<string> &words){
        vector<string> CC; //the vector to store the common chars
        int charCounter[26] = {0};

        //the first word
        for(string::iterator c = words[0].begin(); c != words[0].end(); c++){
            int charIndex = *c - 'a';
            charCounter[charIndex] = charCounter[charIndex] + 1;
        }

        for(vector<string>::iterator i = words.begin() + 1; i != words.end(); i++){
            int temp[26] = {0};
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
    Solution *S = new Solution;

    //input
    vector<string> words{"bella", "label", "roller"};

    vector<string> result = S->commonChars(words);

    for(auto i : result){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}