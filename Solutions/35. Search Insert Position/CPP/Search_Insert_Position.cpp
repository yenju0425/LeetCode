#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>::iterator LB(vector<int>::iterator left, vector<int>::iterator right, int& target) {
        if (left == right) {
            return left;
        }

        vector<int>::iterator half = left + (right - left) / 2;
        if (target > *half) {
            return LB(half + 1, right, target);
        }
        else if (target < *half) {
            return LB(left, half, target);
        }
        else {
            return half;
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return LB(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main() {
    Solution S;

    // inputs
    int target = 5;
    vector<int> nums{1, 3, 5, 6};

    cout << S.searchInsert(nums, target) << endl;

    return 0;
}
