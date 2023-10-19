#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0;
        long avg = 0;

        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            sum = sum + nums[i];
        }

        avg = sum / numsSize;

        // iterate through all nums
        long left = sum;
        long right = 0;
        long minAD = avg;

        int minId = numsSize - 1;
        for (int i = numsSize - 1; i > 0; i--) {
            left = left - nums[i];
            right = right + nums[i];

            long AD = abs(left / i - right / (numsSize - i));

            if (AD <= minAD) {
                minId = i - 1;
                minAD = AD;
            }
        }

        return minId;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{2, 5, 3, 9, 5, 3};

    cout << S->minimumAverageDifference(nums) << endl;

    return 0;
}
