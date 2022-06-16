#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int maximumUniqueSubarray(vector<int> &nums){
        int nums_size = nums.size();
        int sum    = 0;
        int maxSum = 0;
        int left   = 0;
        int right  = 0;

        unordered_set<int> numsUsed;

        while(true){
            if(right != left and numsUsed.count(nums[right])){
                numsUsed.erase(nums[left]);
                sum = sum - nums[left];
                left = left + 1;
            }
            else{
                numsUsed.insert(nums[right]);
                sum = sum + nums[right];
                right = right + 1;
            }

            maxSum = max(maxSum, sum);
            
            if(right == nums_size){
                break;
            }
        }

        return maxSum;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};

    cout << S->maximumUniqueSubarray(nums) << endl;

    return 0;
}