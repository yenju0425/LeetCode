#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minOperations(vector<int> &nums, int x){
        int target = -x;
        int nums_size = nums.size();
        for(int i = 0; i < nums_size; i++){
            target = target + nums[i];
        }

        if(target < 0){
            return -1;
        }

        //look for the longest interval which sum is equal to target
        int left  = 0;
        int right = 0;

        int currentSum      =  0;
        int longestInterval = -1;
        while(true){
            if(currentSum < target){
                if(right == nums_size){
                    break;
                }
                currentSum = currentSum + nums[right];
                right = right + 1;
            }
            else if(currentSum > target){
                currentSum = currentSum - nums[left];
                left  = left  + 1;
            }
            else{
                longestInterval = max(longestInterval, right - left);

                if(right == nums_size){
                    break;
                }
                currentSum = currentSum + nums[right] - nums[left];
                right = right + 1;
                left  = left  + 1;
            }
        }

        return (longestInterval != -1) ? nums_size - longestInterval : -1;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int x = 5;
    vector<int> nums{1, 1, 3, 2, 5};

    cout << S->minOperations(nums, x) << endl;

    return 0;
}