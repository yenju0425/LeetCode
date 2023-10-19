#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    void rotate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        k = k % nums_size;

        int numOfIter = gcd(nums_size, k);
        for (int i = 0; i < numOfIter; i++) {
            int cur_idx = i;
            int nxt_idx = (cur_idx + nums_size - k) % nums_size;
            while (nxt_idx != i) {
                swap(nums[cur_idx], nums[nxt_idx]);
                cur_idx = nxt_idx;
                nxt_idx = (cur_idx + nums_size - k) % nums_size;
            }
        }
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int k = 3;
    vector<int> nums{-1, -100, 3, 99};

    S->rotate(nums, k);

    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
