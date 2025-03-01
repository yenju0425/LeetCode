#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int counter = 0;

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > k) {
                j = j - 1;
            } else if (sum < k) {
                i = i + 1;
            } else {
                counter = counter + 1;
                j       = j - 1;
                i       = i + 1;
            }
        }

        return counter;
    }
};

int main() {
    Solution S;

    int k = 5;
    vector<int> nums{1, 2, 3, 4};

    cout << S.maxOperations(nums, k) << endl;

    return 0;
}
