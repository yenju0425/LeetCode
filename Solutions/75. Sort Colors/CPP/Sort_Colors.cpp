#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int nums_size = nums.size();

        int left = 0;
        int right = nums_size - 1;

        int idx = 0;
        while (idx <= right) {
            if (idx < left || nums[idx] == 1) {
                idx = idx + 1;
            }
            else if (nums[idx] == 0) {
                swap(nums[idx], nums[left]);
                left = left + 1;
            }
            else {
                swap(nums[idx], nums[right]);
                right = right - 1;
            }
        }
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{2, 0, 2, 1, 1, 0};

    S.sortColors(nums);

    for (auto i : nums) {
        cout << i << ' ';
    }

    return 0;
}
