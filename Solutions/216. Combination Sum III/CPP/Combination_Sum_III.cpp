#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum3(int k, int n){
        return combinationSum3(k, n, 1);
    }

    vector<vector<int>> combinationSum3(int k, int n, int lowerBound){
        if(k == 0 and n == 0){
            return vector<vector<int>>{{}};
        }
        if(k <= 0 or n <= 0){
            return vector<vector<int>>{};
        }
        vector<vector<int>> comb;
        int upperbound = min(9, n / k);
        for(int i = lowerBound; i <= upperbound; i++){
            vector<vector<int>> postComb = combinationSum3(k - 1, n - i, i + 1);
            if(!postComb.empty()){
                int postCombSize = postComb.size();
                for(int j = 0; j < postCombSize; j++){
                    postComb[j].push_back(i);
                }
                comb.insert(comb.end(), postComb.begin(), postComb.end());
            }
        }
        return comb;
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