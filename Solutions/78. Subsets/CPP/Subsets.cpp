#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> s_set;
    vector<vector<int>> s_sets;

public:
    void generateSunsets(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            s_sets.push_back(s_set);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            s_set.push_back(nums[i]);
            generateSunsets(nums, i + 1);
            s_set.pop_back();
        }
        generateSunsets(nums, nums.size());
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        generateSunsets(nums, 0);
        return s_sets;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{1, 2, 3};

    vector<vector<int>> result = S.subsets(nums);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
