#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int& target, int left, int right) {
        if (left >= right) {
            return false;
        }

        int idx = (left + right) / 2;
        if (nums[idx] == target) {
            return true;
        }

        if (nums[left] < nums[idx] || nums[idx] > nums[right - 1]) {
            if (nums[left] <= target && target < nums[idx]) {
                return binary_search(nums, target, left, idx);
            } else {
                return binary_search(nums, target, idx + 1, right);
            }
        } else if (nums[idx] < nums[right - 1] || nums[left] > nums[idx]) {
            if (nums[idx] < target && target <= nums[right - 1]) {
                return binary_search(nums, target, idx + 1, right);
            } else {
                return binary_search(nums, target, left, idx);
            }
        } else {
            return binary_search(nums, target, left, idx) || binary_search(nums, target, idx + 1, right);
        }
    }

    int search(vector<int>& nums, int target) { return binary_search(nums, target, 0, nums.size()); }
};

int main() {
    Solution S;

    int target = 1;
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};

    cout << S.search(nums, target);

    return 0;
}
