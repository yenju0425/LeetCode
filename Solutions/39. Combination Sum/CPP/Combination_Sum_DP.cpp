#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int numOfCandidates = candidates.size();

        vector<vector<vector<vector<int>>>> combanations(numOfCandidates + 1, vector<vector<vector<int>>>(target + 1));
        for(int i = 0; i <= numOfCandidates; ++i) {
            combanations[i][0].push_back(vector<int>{});
        }

        for(int i = 1; i <= numOfCandidates; ++i) {
            for(int j = 1; j <= target; ++j) {
                //combanations[i][j] = "not to use the i-th num" + "use the i-th num" (to have a sum of j)
    
                //not to use the i-th num
                combanations[i][j] = combanations[i - 1][j];

                //use the i-th num
                int ith_num = candidates[i - 1];
                int pre_sum = j - ith_num;
                if(pre_sum >= 0) {
                    vector<vector<int>> pre_comb = combanations[i][pre_sum];
                    for(vector<vector<int>>::iterator iter = pre_comb.begin(); iter != pre_comb.end(); iter++) {
                        (*iter).push_back(ith_num);
                    }
                    combanations[i][j].insert(combanations[i][j].end(), pre_comb.begin(), pre_comb.end());
                }
            }
        }

        return combanations[numOfCandidates][target];
    }
};

int main() {
    Solution S;

    //inputs
    int target = 8;
    vector<int> candidates{2, 3, 5};

    vector<vector<int>> result = S.combinationSum(candidates, target);

    for(auto i : result) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
