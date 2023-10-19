#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS = findLIS(nums, -1, 0);

        for (const int& i : LIS) {
            cout << i << " ";
        }
        cout << endl;

        return LIS.size();
    }

    vector<int> findLIS(vector<int>& nums, int previousIndex, int currentIndex) {
        if (currentIndex >= nums.size()) {
            return vector<int>();
        }

        vector<int> takeCurrentIndex;
        if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
            takeCurrentIndex = findLIS(nums, currentIndex, currentIndex + 1);
            takeCurrentIndex.push_back(nums[currentIndex]);
        }

        vector<int> skipCurrentIndex = findLIS(nums, previousIndex, currentIndex + 1);

        return takeCurrentIndex.size() > skipCurrentIndex.size() ? takeCurrentIndex : skipCurrentIndex;
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
