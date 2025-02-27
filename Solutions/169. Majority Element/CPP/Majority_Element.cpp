#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nums_size = nums.size();
        unordered_map<long, long> M;
        for (int i = 0; i < nums_size; i++) {
            if (M.count(nums[i])) {
                M[nums[i]] = M[nums[i]] + 1;
            } else {
                M[nums[i]] = 1;
            }

            if (M[nums[i]] > (nums_size / 2)) {
                return nums[i];
            }
        }

        return -1;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};

    cout << S.majorityElement(nums) << endl;

    return 0;
}
