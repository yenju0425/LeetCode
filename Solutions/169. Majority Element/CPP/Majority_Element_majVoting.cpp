#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int majority = 0;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            if (counter == 0) {
                majority = nums[i];
            }
            counter = (nums[i] == majority) ? counter + 1 : counter - 1;
        }

        return majority;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};

    cout << S->majorityElement(nums) << endl;

    return 0;
}
