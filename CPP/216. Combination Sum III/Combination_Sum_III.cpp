#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
    }
};

int main(){
    Solution* S = new Solution();
    vector<vector<int>> comb = S->combinationSum3(3, 9);
    for(int i = 0; i < comb.size(); i++){
        for(int j = 0; j < comb[i].size(); j++){
            cout << comb[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}