#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permutation(vector<pair<int, int>> numList){
        vector<vector<int>> P{};
        int numList_size = numList.size();
        for(int i = 0; i < numList_size; i++){
            //get the first number
            int prefix = numList[i].first;

            //get the permutation of the remaining numbers
            vector<pair<int, int>> new_numList = numList;
            new_numList[i].second = new_numList[i].second - 1;
            if(new_numList[i].second == 0){
                new_numList.erase(new_numList.begin() + i);
            }

            vector<vector<int>> p = permutation(new_numList);
            if(p.empty()){
                p = vector<vector<int>>{{}};
            }

            int p_size = p.size();
            for(int j = 0; j < p_size; j++){
                p[j].push_back(prefix);
                P.push_back(p[j]);
            }
        }
        return P;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());

        //create number list
        vector<pair<int, int>> numList;
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
    vector<int> nums{1, 1, 2, 2, 3};
    vector<vector<int>> result = S->permuteUnique(nums);
    cout << "number of permutations: " << result.size() << endl;
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}