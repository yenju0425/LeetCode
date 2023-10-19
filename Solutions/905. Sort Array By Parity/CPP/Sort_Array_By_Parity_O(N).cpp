#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int l = 0, r = nums.size() - 1; l < r; l++, r--) {
            // find the first odd num from left
            while (!(nums[l] & 1) && l < r) {
                l = l + 1;
            }

            // find the first even num from right
            while ((nums[r] & 1) && l < r) {
                r = r - 1;
            }

            swap(nums[l], nums[r]);
        }

        return nums;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{3, 1, 2, 4};

    vector<int> result = S->sortArrayByParity(nums);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
