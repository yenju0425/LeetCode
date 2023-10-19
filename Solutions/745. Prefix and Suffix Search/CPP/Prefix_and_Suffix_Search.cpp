// Reference: https://leetcode.com/problems/prefix-and-suffix-search/discuss/1185249/C%2B%2B-No-TRIE-A-HashMap-soln.
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class WordFilter {
public:
    unordered_map<string, int> UM;

    WordFilter(vector<string>& words) {
        int words_size = words.size();
        for (int i = 0; i < words_size; i++) {
            string word = words[i];
            int wordsLength = word.length();

            string prefix;
            for (int j = 0; j < wordsLength; j++) {
                prefix = prefix + word[j];
                string suffix;
                for (int k = wordsLength - 1; k >= 0; k--) {
                    suffix = word[k] + suffix;
                    UM[prefix + "|" + suffix] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        unordered_map<string, int>::iterator iter = UM.find(prefix + "|" + suffix);
        return (iter == UM.end()) ? -1 : iter->second;
    }
};

int main() {
    // inputs
    string prefix = "a";
    string suffx = "e";
    vector<string> words{"cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba"};

    WordFilter* W = new WordFilter(words);

    cout << W->f("ac", "accabaccaa") << endl;

    return 0;
}
