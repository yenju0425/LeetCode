#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutation(unordered_map<int, int>& numCount) {
        vector<vector<int>> P;
        for (unordered_map<int, int>::iterator iter = numCount.begin(); iter != numCount.end(); ++iter) {
            if (iter->second == 0) {
                continue;
            }

            // get the first number
            iter->second = iter->second - 1;

            // get the permutation of the remaining numbers
            vector<vector<int>> p = permutation(numCount);

            int p_size = p.size();
            for (int j = 0; j < p_size; ++j) {
                p[j].push_back(iter->first);
                P.push_back(p[j]);
            }

            // restore numCount
            iter->second = iter->second + 1;
        }

        return P.empty() ? vector<vector<int>>{{}} : P;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // create numCount
        unordered_map<int, int> numCount;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            int num       = nums[i];
            numCount[num] = (numCount.count(num) == 0) ? 1 : numCount[num] + 1;
        }

        return permutation(numCount);
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{3, 3, 0, 3};

    vector<vector<int>> result = S.permuteUnique(nums);

    cout << "number of permutations: " << result.size() << endl;
    for (auto i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
