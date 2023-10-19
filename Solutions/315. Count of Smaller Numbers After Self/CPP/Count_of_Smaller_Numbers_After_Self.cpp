#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void mergeSort(vector<pair<int, int>>& numsIdx, vector<int>& result, int left, int right) {
        if (right - left <= 1) {
            return;
        }

        int idx = (left + right) / 2;

        mergeSort(numsIdx, result, left, idx);
        mergeSort(numsIdx, result, idx, right);

        // merge
        int temp = 0, l = left, r = idx, size = right - left;
        vector<pair<int, int>> merge(size);

        for (int i = 0; i < size; i++) {
            if (r >= right || (l < idx and numsIdx[l].first <= numsIdx[r].first)) {
                result[numsIdx[l].second] = result[numsIdx[l].second] + temp;
                merge[i] = numsIdx[l];
                l = l + 1;
            }
            else {
                merge[i] = numsIdx[r];
                r = r + 1;
                temp = temp + 1;
            }
        }

        copy(merge.begin(), merge.end(), numsIdx.begin() + left);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int nums_size = nums.size();

        vector<int> result(nums_size, 0);
        vector<pair<int, int>> numsIdx(nums_size);
        for (int i = 0; i < nums_size; i++) {
            numsIdx[i] = pair<int, int>{nums[i], i};
        }

        mergeSort(numsIdx, result, 0, nums_size);

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> nums{5, 2, 6, 1};

    vector<int> result = S->countSmaller(nums);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
