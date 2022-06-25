#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int binary_search(vector<int> &nums, int left, int right, int target){
        if(left >= right){
            return -1;
        }

        int idx = (left + right) / 2;
        if(nums[idx] == target){
            return idx;
        }
        
        if(nums[left] < nums[idx]){
            if(nums[left] <= target and target < nums[idx]){
                return binary_search(nums, left, idx, target);
            }
            else{
                return binary_search(nums, idx + 1, right, target);
            }
        }
        else{
            if(nums[idx] < target and target <= nums[right - 1]){
                return binary_search(nums, idx + 1, right, target);
            }
            else{
                return binary_search(nums, left, idx, target);
            }
        }
    }

    int search(vector<int> &nums, int target){
        return binary_search(nums, 0, nums.size(), target);
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int target = 2;
    vector<int> nums{3, 4, 5, 6, 1, 2};

    cout << S->search(nums, target) << endl;

    return 0;
}