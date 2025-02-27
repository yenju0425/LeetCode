#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int nums_size = nums.size();
        int sum       = 0;
        int maxSum    = 0;
        int left      = 0;
        int right     = 0;

        unordered_set<int> US;

        while (right != nums_size) {
            if (right != left && US.count(nums[right])) {
                US.erase(nums[left]);
                sum  = sum - nums[left];
                left = left + 1;
            } else {
                US.insert(nums[right]);
                sum   = sum + nums[right];
                right = right + 1;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};

    cout << S.maximumUniqueSubarray(nums) << endl;

    return 0;
}
