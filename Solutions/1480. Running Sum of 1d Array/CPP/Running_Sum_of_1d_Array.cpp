#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> result(nums_size, 0);  // init result with size of nums_size

        int temp = 0;

        for (int i = 0; i < nums_size; i++) {
            temp      = temp + nums[i];
            result[i] = temp;
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{1, 2, 3, 4};

    vector<int> result = S.runningSum(nums);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
