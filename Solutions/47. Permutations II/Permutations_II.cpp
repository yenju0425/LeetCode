#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permutation(vector<pair<int, int>> numList){
        vector<vector<int>> P = {};
        int numList_size = numList.size();
        for(int i = 0; i < numList_size; i++){
            if(numList[i].second > 0){
                // get the first number
                int prefix = numList[i].first;

                // get the permutation of the remaining numbers
                numList[i].second = numList[i].second - 1;
                vector<vector<int>> p = permutation(numList);
                numList[i].second = numList[i].second + 1;

                if(p.empty()){
                    p.push_back(vector<int>());
                }
                int p_size = p.size();
                for(int j = 0; j < p_size; j++){
                    p[j].push_back(prefix);
                    P.push_back(p[j]);
                }
            }
        }
        return P;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<pair<int, int>> numList;
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        for(int i = 0; i < nums_size; i++){
            if(numList.empty() or numList.back().first != nums[i]){
                numList.push_back(pair<int, int>(nums[i], 1));
            }
            else{
                numList.back().second = numList.back().second + 1;
            }
        }
        return permutation(numList);
    }
};

int main(){
    Solution* S = new Solution();
    vector<int>nums{1, 1, 3};
    vector<vector<int>> result = S->permuteUnique(nums);
    return 0;
}