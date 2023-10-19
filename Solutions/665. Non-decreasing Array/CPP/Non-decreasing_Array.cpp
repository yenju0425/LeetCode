#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int nums_size = nums.size();

        int errorCounter = 0;
        for (int i = 2; i < nums_size; i++) {
            if (nums[i - 2] > nums[i - 1]) {
                errorCounter = errorCounter + 1;
            }
            if (nums[i - 1] > nums[i]) {
                errorCounter = errorCounter + 1;
                if (nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                }
                else {
                    nums[i] = nums[i - 1];
                }
            }

            if (errorCounter == 2) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{5, 4, 3};

    cout << S->checkPossibility(nums) << endl;

    return 0;
}
