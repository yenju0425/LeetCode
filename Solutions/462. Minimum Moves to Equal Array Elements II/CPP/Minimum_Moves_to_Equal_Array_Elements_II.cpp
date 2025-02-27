#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int nums_size = nums.size();

        sort(nums.begin(), nums.end());

        int mid = nums[nums_size / 2];

        int distance = 0;
        for (int i = 0; i < nums_size; i++) {
            distance = distance + abs(nums[i] - mid);
        }

        return distance;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{1, 10, 2, 9};

    cout << S.minMoves2(nums) << endl;

    return 0;
}
