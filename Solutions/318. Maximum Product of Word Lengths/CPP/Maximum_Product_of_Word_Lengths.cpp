#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string &lhs, string &rhs){
    return lhs.length() > rhs.length();
}

class Solution{
public:
    int maxProduct(vector<string> &words){
        sort(words.begin(), words.end(), cmp);

        int numOfWords = words.size();

        //existChar: if words[i] hold char j, then existChar[i][j] will be set to true
        vector<vector<bool>> existChar(numOfWords, vector<bool>(26, false));

        //wordsLen: store the length of each word
        vector<int> wordsLen(numOfWords, 0);

        //complete existChar and wordsLen
        for(int i = 0; i < numOfWords; i++){
            string word = words[i];
            int wordLen = word.length();
            wordsLen[i] = wordLen;
            for(int j = 0; j < wordLen; j++){
                char c = word[j];
                existChar[i][c - 'a'] = true;
            }
        }

        int maxP = 0;
        for(int i = 1; i < numOfWords; i++){
            for(int j = 0; j < i and wordsLen[i] * wordsLen[j] > maxP; j++){
                bool collision = false;
                for(int k = 0; k < wordsLen[i]; k++){
                    char c = words[i][k];
                    if(existChar[j][c - 'a'] == true){
                        collision = true;
                        break;
                    }
                }

                if(!collision){
                    maxP = wordsLen[i] * wordsLen[j];
                }
            }
        }

        return maxP;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<string> coins{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    cout << S->maxProduct(coins) << endl;

    return 0;
}