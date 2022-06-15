#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target){
        vector<int> result(2, -1);

        if(!binary_search(nums.begin(), nums.end(), target)){
            return result;
        }
        
        result[0] = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        result[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int target = 8;
    vector<int> nums{5, 7, 7, 8, 8, 10};

    vector<int> result = S->searchRange(nums, target);

    for(auto i : result){
        cout << i << ' ';
    }

    return 0;
}