#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> result;

        if (nums.empty()) {
            return result;
        }

        // sort nums[i]
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            sort(nums[i].begin(), nums[i].end());
        }

        int size = nums[0].size();
        for (int i = 0; i < size; i++) {
            bool found = true;
            for (int j = 0; j < nums_size && found; j++) {
                if (!binary_search(nums[j].begin(), nums[j].end(), nums[0][i])) {
                    found = false;
                }
            }
            if (found) {
                result.push_back(nums[0][i]);
            }
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    vector<vector<int>> sets{
        {1, 2, 3},
        {1, 3, 9},
        {1, 2, 8, 3}};

    vector<int> result = S->intersection(sets);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
