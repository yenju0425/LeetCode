#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        if (nums.empty()) {
            return vector<int>{};
        }

        vector<int> result = nums[0];

        int nums_size = nums.size();
        for (int i = 1; i < nums_size; i++) {
            unordered_set<int> US(nums[i].begin(), nums[i].end());

            for (vector<int>::iterator iter = result.begin(); iter != result.end();) {
                if (US.count(*iter)) {
                    iter = iter + 1;
                }
                else {
                    result.erase(iter);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution* S = new Solution();

    vector<vector<int>> sets{
        {1, 2, 3},
        {1, 3, 9},
        {1, 2, 8, 3}
    };

    vector<int> result = S->intersection(sets);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
