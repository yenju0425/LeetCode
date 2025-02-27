#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int& target, int left, int right) {
        if (left >= right) {
            return -1;
        }

        int idx = (left + right) / 2;
        if (nums[idx] == target) {
            return idx;
        }

        if (nums[left] < nums[idx]) {
            if (nums[left] <= target && target < nums[idx]) {
                return binary_search(nums, target, left, idx);
            } else {
                return binary_search(nums, target, idx + 1, right);
            }
        } else {
            if (nums[idx] < target && target <= nums[right - 1]) {
                return binary_search(nums, target, idx + 1, right);
            } else {
                return binary_search(nums, target, left, idx);
            }
        }
    }

    int search(vector<int>& nums, int target) { return binary_search(nums, target, 0, nums.size()); }
};

int main() {
    Solution S;

    int target = 2;
    vector<int> nums{3, 4, 5, 6, 1, 2};

    cout << S.search(nums, target) << endl;

    return 0;
}
