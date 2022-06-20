//Reference: https://leetcode.com/problems/short-encoding-of-words/discuss/125811/C%2B%2BJavaPython-Easy-Understood-Solution-with-Explanation
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int minimumLengthEncoding(vector<string> &words){
        unordered_set<string> pruned_words(words.begin(), words.end());

        int numOfWords = words.size();
        for(int i = 0; i < numOfWords; i++){
            int word_length = words[i].length();
            for(int j = 1; j < word_length; j++){
                pruned_words.erase(words[i].substr(j));
            }
        }

        int minLength = 0;
        for(unordered_set<string>::iterator iter = pruned_words.begin(); iter != pruned_words.end(); iter++){
            minLength = minLength + iter->length() + 1;
        }

        return minLength;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<string> words{"time", "me", "bell"};

    cout << S->minimumLengthEncoding(words) << endl;

    return 0;
}