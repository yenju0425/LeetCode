#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int target;
    vector<int> candidates;
    vector<int> currentComb;
    vector<vector<int>> result;

public:
    void combGenerator(int startFrom, int currentSum){
        if(currentSum > target){
            return;
        }
        else if(currentSum == target){
            result.push_back(currentComb);
            return;
        }

        int numOfcandidates = candidates.size();
        for(int i = startFrom; i < numOfcandidates; i++){
            currentComb.push_back(candidates[i]);
            combGenerator(i, currentSum + candidates[i]);
            currentComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        this->target      = target;
        this->candidates  = candidates;
        this->currentComb = vector<int>{};

        combGenerator(0, 0);

        return result;
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    int target = 8;
    vector<int> candidates{2, 3, 5};

    vector<vector<int>> result = S->combinationSum(candidates, target);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}