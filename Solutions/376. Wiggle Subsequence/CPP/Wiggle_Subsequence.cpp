#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int nums_size = nums.size();
        for (int i = nums_size - 1; i > 0; i--) {
            nums[i] = nums[i] - nums[i - 1];
        }

        int result = 1;
        int pre = 0;
        int cur = 0;
        for (int i = 1; i < nums_size; i++) {
            if (pre == 0) {
                pre = nums[i];
            }
            else {
                cur = nums[i];
                if (cur != 0 and (pre ^ cur) < 0) {
                    result = result + 1;
                    pre = cur;
                }
            }
        }

        return (pre == 0) ? 1 : result + 1;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{1, 2, 3};

    cout << S->wiggleMaxLength(nums) << endl;

    return 0;
}
