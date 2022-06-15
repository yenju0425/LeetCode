#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    int target;

    int numOfCandidates;
    vector<int> candidates;

    int getNumIdx_size;
    vector<int> getNumIdx;

    vector<int> currentComb;
    vector<vector<int>> result;

public:
    void combGenerator(int currentNumIdx, int currentSum, int currentNumId){
        if(currentSum > target){
            return;
        }
        if(currentSum == target){
            result.push_back(currentComb);
            return;
        }
        if(currentNumIdx >= numOfCandidates){
            return;
        }

        for(int i = currentNumId; i < getNumIdx_size; i++){
            int currentNum = candidates[getNumIdx[i]];
            currentComb.push_back(currentNum);

            int nextIdx   = max(currentNumIdx + 1, getNumIdx[i] + 1);
            int nextNumId = i + (nextIdx == numOfCandidates or currentNum != candidates[nextIdx]);
            combGenerator(nextIdx, currentSum + currentNum, nextNumId);

            currentComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        //sort candidates
        sort(candidates.begin(), candidates.end());

        //init
        this->target = target;
        this->candidates = candidates;
        this->numOfCandidates = candidates.size();
        for(int i = 0; i < numOfCandidates; i++){
            if(i == 0 or candidates[i] != candidates[i - 1]){
                this->getNumIdx.push_back(i);
            }
        }
        this->getNumIdx_size = getNumIdx.size();

        //generate combinations
        combGenerator(0, 0, 0);

        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int target = 8;
    vector<int> candidates{3, 1, 3, 5, 1, 1};

    vector<vector<int>> result = S->combinationSum2(candidates, target);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}