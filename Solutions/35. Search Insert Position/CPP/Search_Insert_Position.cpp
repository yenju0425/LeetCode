#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int>::iterator lb(vector<int>::iterator left, vector<int>::iterator right, int &target){
        if(left == right){
            return left;
        }

        vector<int>::iterator half = left + (right - left) / 2;
        if(target > *half){
            return lb(half + 1, right, target);
        }
        else if(target < *half){
            return lb(left, half, target);
        }
        else{
            return half;
        }
    }

    int searchInsert(vector<int> &nums, int target){
        return lb(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main(){
    Solution* S = new Solution();

    vector<int> nums{1, 3, 5, 6};

    cout << S->searchInsert(nums, 2) << endl;

    return 0;
}