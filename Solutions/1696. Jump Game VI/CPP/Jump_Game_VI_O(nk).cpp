#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int nums_size = nums.size();
        for (int i = 1; i < nums_size; i++) {
            int maximum = INT_MIN;

            int temp = max(0, i - k);
            for (int j = i - 1; j >= temp; j--) {
                maximum = max(maximum, nums[j]);
            }

            nums[i] = nums[i] + maximum;
        }

        return nums.back();
    }
};

int main() {
    Solution S;

    int k = 2;
    vector<int> nums{100, -1, -100, -1, 100};

    cout << S.maxResult(nums, k) << endl;

    return 0;
}
