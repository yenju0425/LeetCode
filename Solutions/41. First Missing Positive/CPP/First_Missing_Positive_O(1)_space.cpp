// Reference:
// https://leetcode.com/problems/first-missing-positive/discuss/781724/C%2B%2B-simple-5-line-solution-O(n)-time-and-O(1)-space
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = nums.size();

        // init
        for (int i = 0; i < nums_size; ++i) {
            if (nums[i] <= 0) {
                nums[i] = nums_size + 1;  // number > nums_size: invalid
            }
        }

        // using sign to indicate the existance of the corresponding number
        // e.g. nums[5 - 1] = -87 -> '5' do exist
        for (int i = 0; i < nums_size; ++i) {
            int number = abs(nums[i]);
            if (number <= nums_size && nums[number - 1] > 0) {
                nums[number - 1] = -nums[number - 1];
            }
        }

        for (int i = 0; i < nums_size; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return nums_size + 1;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{3, 4, -1, 1};

    cout << S.firstMissingPositive(nums) << endl;

    return 0;
}
