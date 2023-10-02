#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> wordsCount;

        //init wordsCount
        int numOfWords = words.size();
        for(int i = 0; i < numOfWords; ++i) {
            string word = words[i];
            wordsCount[word] = (wordsCount.find(word) == wordsCount.end()) ? 1 : wordsCount[word] + 1;
        }

        int word_len  = words[0].size();
        int last_char = s.size() - numOfWords * word_len;
        unordered_map<string, int> wordsCount_copy = wordsCount;
        for(int i = 0; i <= last_char; ++i) {
            for(int j = 0; j < numOfWords; ++j) { //check one word at a time
                string word = s.substr(i + j * word_len, word_len);

                if(wordsCount_copy.find(word) == wordsCount_copy.end() || wordsCount_copy[word] == 0) {
                    break;
                }
                else {
                    wordsCount_copy[word] = wordsCount_copy[word] - 1;
                }

                if(j == numOfWords - 1) { //every word is found
                    result.push_back(i);
                }
            }

            //get a fresh wordsCount_copy
            wordsCount_copy = wordsCount;
        }

        return result;
    }
};

int main() {
    Solution S;

    //inputs
    string s = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};

    vector<int> result = S.findSubstring(s, words);

    for(auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
