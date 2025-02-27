#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main() {
    Solution S;

    int target = 5;
    vector<int> nums{1, 3, 5, 6};

    cout << S.searchInsert(nums, target) << endl;

    return 0;
}
