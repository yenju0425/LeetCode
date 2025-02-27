#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int best_Solution = nums[0] + nums[1] + nums[2];  // init with arbitrary solution

        int nums_size = nums.size();
        for (int i = 0; i < nums_size - 2; ++i) {
            // skipping same numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left  = i + 1;
            int right = nums_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    // update best_Solution
                    if (sum - target < abs(best_Solution - target)) {
                        best_Solution = sum;
                    }
                    right = right - 1;
                } else if (sum < target) {
                    if (target - sum < abs(best_Solution - target)) {
                        best_Solution = sum;
                    }
                    left = left + 1;
                } else {  // solution found
                    return target;
                }
            }
        }

        return best_Solution;
    }
};

int main() {
    Solution S;

    vector<int> nums{1, 1, 1, 1};
    int target = -100;

    cout << S.threeSumClosest(nums, target) << endl;

    return 0;
}
