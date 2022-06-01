#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> &lfs, vector<int> &rhs){
    return (lfs[0] != rhs[0]) ? lfs[0] < rhs[0] : lfs[1] > rhs[1];
}

class Solution{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes){
        sort(envelopes.begin(), envelopes.end(), cmp);

        //longest increasing subsequence
        int envelopes_size = envelopes.size();
        vector<int> LIS;
        for(int i = 0; i < envelopes_size; i++){
            int index = lower_bound(LIS.begin(), LIS.end(), envelopes[i][1]) - LIS.begin();
            if(index == LIS.size()){
                LIS.push_back(envelopes[i][1]);
            }
            else if(LIS[index] > envelopes[i][1]){
                LIS[index] = envelopes[i][1];
            }
        }
        return LIS.size();
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> envelops{{30, 50}, {12, 2}, {3, 4}, {12, 15}};

    cout << S->maxEnvelopes(envelops) << endl;

    return 0;
}