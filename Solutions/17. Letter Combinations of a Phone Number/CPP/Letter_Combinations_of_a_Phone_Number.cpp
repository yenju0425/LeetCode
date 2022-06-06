#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<string>> charSet{
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    };

public:
    vector<string> letterCombinations(string digits){
        vector<string> combinations{};
        if(digits.size() == 0){
            return combinations;
        }
        
        int c = digits.front() - '2'; //characters start from '2' button
        if(digits.size() == 1){
            return charSet[c];
        }

        digits.erase(digits.begin());
        vector<string> _combinations = letterCombinations(digits);

        int charSet_size = charSet[c].size();
        int _combinations_size = _combinations.size();
        for(int i = 0; i < charSet_size; i++){
            for(int j = 0; j < _combinations_size; j++){
                combinations.push_back(charSet[c][i] + _combinations[j]);
            }
        }

        return combinations;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    string digits = "225";

    vector<string> result = S->letterCombinations(digits);

    for(auto i : result){
        cout << i << endl;
    }

    return 0;
}