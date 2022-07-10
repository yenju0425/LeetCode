#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int countPrefixes(vector<string> &words, string s){
        int counter = 0;
    
        int word_size = words.size();
        for(int i = 0; i < word_size; i++){
            bool match = true;
            for(int j = 0; j < words[i].size() and match; j++){
                if(j >= s.size() or words[i][j] != s[j]){
                    match = false;
                }
            }

            counter = counter + match;
        }

        return counter;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    string s = "aabdk";
    vector<string> words{"aa", "aabd", "c"};

    cout << S->countPrefixes(words, s) << endl;

    return 0;
}