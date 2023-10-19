#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        int minimun = 0;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            sum = sum + nums[i];

            maximum = max(maximum, minimun + sum);
            minimun = max(minimun, -sum);
        }

        return maximum;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << S.maxSubArray(nums) << endl;

    return 0;
}
