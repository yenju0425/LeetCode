#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums){
        //initialize
        int numsSize = nums.size();

        long numsSum = 0;
        long avg = 0;
        for(int i = 0; i < numsSize; i++){
            numsSum += nums[i];
        }
        avg = numsSum / numsSize;

        //iterate through all nums
        long left  = nums[0];
        long right = numsSum - nums[0];
        long minAvgDiff = (numsSize == 1) ? 0 : abs(left - right / (numsSize - 1));
        int index      =  0;
        for(int i = 1; i < numsSize - 1; i++){ //the last calculation will cause error
            left  += nums[i];
            right -= nums[i];
            long avgDiff = abs(left / (i + 1) - right / (numsSize - (i + 1)));
            if(minAvgDiff > avgDiff){
                minAvgDiff = avgDiff;
                index = i;
            }
        }

        //manually check the last avgDiff
        if(minAvgDiff > avg){
            minAvgDiff = avg;
            index = numsSize - 1;
        }

        return index;
    }
};

int main(){
    vector<int> nums{
        5
    };

    Solution *S = new Solution();

    cout << S->minimumAverageDifference(nums) << endl;

    return 0;
}