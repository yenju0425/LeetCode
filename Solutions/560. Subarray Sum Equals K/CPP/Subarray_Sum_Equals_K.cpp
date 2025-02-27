#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = (nums[0] == k);
        unordered_map<int, int> UM{{0, 1}};
        UM[nums[0]] = UM[nums[0]] + 1;

        int nums_size = nums.size();
        for (int i = 1; i < nums_size; i++) {
            nums[i]     = nums[i] + nums[i - 1];
            result      = result + UM[nums[i] - k];
            UM[nums[i]] = UM[nums[i]] + 1;
        }

        return result;
    }
};

int main() {
    Solution S;

    int k = 2;
    vector<int> nums{1, 1, 1};

    cout << S.subarraySum(nums, k) << endl;

    return 0;
}
