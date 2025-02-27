#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { return findLIS(nums, -1, 0); }

    int findLIS(vector<int>& nums, int previousIndex, int currentIndex) {
        if (currentIndex >= nums.size()) {
            return 0;
        }

        int takeCurrentIndex = 0;
        if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
            takeCurrentIndex = findLIS(nums, currentIndex, currentIndex + 1) + 1;
        }

        int skipCurrentIndex = findLIS(nums, previousIndex, currentIndex + 1);

        return max(skipCurrentIndex, takeCurrentIndex);
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
