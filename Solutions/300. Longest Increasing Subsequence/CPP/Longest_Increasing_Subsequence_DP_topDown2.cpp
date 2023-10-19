#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> LISLengths;

public:
    int lengthOfLIS(vector<int>& nums) {
        LISLengths = vector<int>(nums.size() + 1, 0);

        return findLIS(nums, nums.size(), 0);
    }

    int findLIS(vector<int>& nums, int previousIndex, int currentIndex) {
        if (currentIndex >= nums.size()) {
            return 0;
        }

        if (LISLengths[previousIndex] > 0) {
            return LISLengths[previousIndex];
        }

        int takeCurrentIndex = 0;
        if (previousIndex == nums.size() || nums[currentIndex] > nums[previousIndex]) {
            takeCurrentIndex = findLIS(nums, currentIndex, currentIndex + 1) + 1;
        }

        int skipCurrentIndex = findLIS(nums, previousIndex, currentIndex + 1);

        LISLengths[previousIndex] = max(skipCurrentIndex, takeCurrentIndex);
        return LISLengths[previousIndex];
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
