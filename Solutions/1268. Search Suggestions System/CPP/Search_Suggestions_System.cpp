#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;

        sort(products.begin(), products.end());

        string word;
        int searchWordLength = searchWord.length();
        for (int i = 0; i < searchWordLength; i++) {
            vector<string> suggestions;

            word = word + searchWord[i];

            // get lower bound
            vector<string>::iterator LB = lower_bound(products.begin(), products.end(), word);

            // get upper bound
            string nextWord             = word;
            nextWord.back()             = nextWord.back() + 1;
            vector<string>::iterator UB = lower_bound(products.begin(), products.end(), nextWord);

            int numOfItem = min(int(UB - LB), 3);
            for (int j = 0; j < numOfItem; j++) {
                suggestions.push_back(*(LB + j));
            }

            result.push_back(suggestions);
        }

        return result;
    }
};

int main() {
    Solution S;

    string searchWord = "mouse";
    vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};

    vector<vector<string>> result = S.suggestedProducts(products, searchWord);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
