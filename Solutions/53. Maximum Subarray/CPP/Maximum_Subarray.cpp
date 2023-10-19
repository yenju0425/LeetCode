#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            sum = sum + nums[i];

            maxSum = max(maxSum, sum);
            sum = max(sum, 0);  // re-accumulate sum
        }

        return maxSum;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{-2};

    cout << S.maxSubArray(nums) << endl;

    return 0;
}
