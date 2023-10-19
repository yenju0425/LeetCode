#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int nums_size;
    vector<int> nums;
    vector<int> subset;
    vector<vector<int>> subsets;

public:
    void subsetsGenerator(int idx) {
        if (idx == nums_size) {
            subsets.push_back(subset);
            return;
        }

        // take
        subset.push_back(nums[idx]);
        subsetsGenerator(idx + 1);
        subset.pop_back();

        // skip
        while (idx + 1 < nums_size && nums[idx] == nums[idx + 1]) {
            idx = idx + 1;
        }
        subsetsGenerator(idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        this->nums_size = nums.size();
        this->nums = nums;

        subsetsGenerator(0);

        return subsets;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{1, 2, 2};

    vector<vector<int>> result = S.subsetsWithDup(nums);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
