#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = nums.size();
        vector<bool> doExist(nums_size + 1, false);
        for (int i = 0; i < nums_size; ++i) {
            int number = nums[i];
            if (number > 0 && number <= nums_size) {
                doExist[number] = true;
            }
        }

        for (int i = 1; i <= nums_size; ++i) {
            if (!doExist[i]) {
                return i;
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
