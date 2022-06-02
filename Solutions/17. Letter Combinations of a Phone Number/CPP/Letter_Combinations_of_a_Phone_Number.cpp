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
        if(digits.size() == 0){
            return vector<string>{};
        }
        
        int c = digits.back() - '2';
        if(digits.size() == 1){
            return charSet[c];
        }
        digits.pop_back();
        vector<string> preComb = letterCombinations(digits);
        int c_charSetSize = charSet[c].size();
        int preCombSize = preComb.size();
        vector<string> Comb;
        for(int i = 0; i < c_charSetSize; i++){
            for(int j = 0; j < preCombSize; j++){
                Comb.push_back(preComb[j] + charSet[c][i]);
            }
        }
        return Comb;
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