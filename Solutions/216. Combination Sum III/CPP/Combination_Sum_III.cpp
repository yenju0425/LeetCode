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
    Solution *S = new Solution();

    //inputs
    int k = 3;
    int n = 9;

    vector<vector<int>> comb = S->combinationSum3(k, n);

    for(auto i : comb){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}