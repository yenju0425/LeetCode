#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        map<int, int, greater<int>> M;
        M[nums[0]] = 1;

        int nums_size = nums.size();
        for (int i = 1; i < nums_size; i++) {
            nums[i] = nums[i] + M.begin()->first;

            M[nums[i]] = M.count(nums[i]) ? M[nums[i]] + 1 : 1;

            if (i >= k) {
                if (M[nums[i - k]] == 1) {
                    M.erase(nums[i - k]);
                }
                else {
                    M[nums[i - k]] = M[nums[i - k]] - 1;
                }
            }
        }

        return nums.back();
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int k = 2;
    vector<int> nums{100, -1, -100, -1, 100};

    cout << S->maxResult(nums, k) << endl;

    return 0;
}
