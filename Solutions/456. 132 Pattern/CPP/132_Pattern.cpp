#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> intervals;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            vector<int>::iterator pos = lower_bound(intervals.begin(), intervals.end(), nums[i], [](int lhs, int rhs) { return lhs > rhs; });
            if ((pos - intervals.begin()) % 2 == 1) {
                if (*pos == nums[i]) {
                    pos = pos + 1;
                }
                else {
                    return true;
                }
            }
            else {
                if (pos == intervals.end()) {
                    intervals.push_back(nums[i]);
                    intervals.push_back(nums[i]);
                }
                else {
                    *pos = nums[i];
                    *(pos + 1) = *(intervals.end() - 1);
                    intervals.erase(pos + 2, intervals.end());
                }
            }
        }

        return false;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{-2, 1, -2};

    cout << S->find132pattern(nums) << endl;

    return 0;
}
