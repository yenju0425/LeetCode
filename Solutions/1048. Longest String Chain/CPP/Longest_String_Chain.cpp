#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    bool isPredecessor(string &w1, string &w2){
        int w2_length = w2.length();
        for(int i = 0; i < w2_length; i++){
            string temp = w2;
            temp.erase(temp.begin() + i);
            if(w1 == temp){
                return true;
            }
        }

        return false;
    }

    int longestStrChain(vector<string> &words){
        sort(words.begin(), words.end(), [](string &w1, string &w2){
            return w1.size() < w2.size();
        });

        int numOfWords = words.size();
        vector<int> strChainLength(numOfWords, 1);

        int maxLength = 1;
        for(int i = 1; i < numOfWords; i++){
            for(int j = i - 1; j >= 0; j--){
                int diff = words[i].length() - words[j].length();
                if(diff == 0){
                    continue;
                }
                else if(diff == 1){
                    if(isPredecessor(words[j], words[i])){
                        strChainLength[i] = max(strChainLength[i], strChainLength[j] + 1);
                    }
                }
                else{
                    break;
                }
            }

            maxLength = max(maxLength, strChainLength[i]);
        }

        return maxLength;
    }
};

int main(){
    Solution *S = new Solution;

    //input
    vector<string> words{"a", "ab", "ac", "bd", "abc", "abd", "abdd"};

    cout << S->longestStrChain(words) << endl;

    return 0;
}