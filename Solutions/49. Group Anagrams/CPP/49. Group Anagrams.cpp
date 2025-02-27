#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int numOfstrs = strs.size();

        // count chars of strs
        vector<vector<int>> charCounter(numOfstrs, vector<int>(26, 0));
        for (int i = 0; i < numOfstrs; ++i) {
            int strLength = strs[i].length();
            for (int j = 0; j < strLength; ++j) {
                int c             = strs[i][j] - 'a';
                charCounter[i][c] = charCounter[i][c] + 1;
            }
        }

        // classify strs
        map<vector<int>, vector<string>> classifier;
        for (int i = 0; i < numOfstrs; ++i) {
            if (classifier.count(charCounter[i]) == 0) {
                classifier[charCounter[i]] = vector<string>{strs[i]};
            } else {
                classifier[charCounter[i]].push_back(strs[i]);
            }
        }

        // counvert classifier (map) to vector
        vector<vector<string>> result;
        for (map<vector<int>, vector<string>>::iterator iter = classifier.begin(); iter != classifier.end(); ++iter) {
            result.push_back(iter->second);
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = S.groupAnagrams(strs);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
