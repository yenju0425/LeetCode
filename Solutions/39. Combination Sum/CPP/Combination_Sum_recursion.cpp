#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int target;

    int numOfCandidates;
    vector<int> candidates;

    vector<int> currentComb;
    vector<vector<int>> result;

public:
    void combGenerator(int currentNumIdx, int currentSum){
        if(currentSum > target){
            return;
        }
        else if(currentSum == target){
            result.push_back(currentComb);
            return;
        }

        for(int i = currentNumIdx; i < numOfCandidates; i++){
            currentComb.push_back(candidates[i]);
            combGenerator(i, currentSum + candidates[i]);
            currentComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        this->target = target;
        this->candidates = candidates;
        this->numOfCandidates = candidates.size();

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