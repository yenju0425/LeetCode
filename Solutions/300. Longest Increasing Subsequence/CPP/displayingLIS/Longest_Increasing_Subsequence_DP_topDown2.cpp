#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> LISs;

public:
    int lengthOfLIS(vector<int>& nums) {
        LISs = vector<vector<int>>(nums.size() + 1, vector<int>());

        vector<int> LIS = findLIS(nums, nums.size(), 0);

        for (const int& currentIndex : LIS) {
            cout << currentIndex << " ";
        }
        cout << endl;

        return LIS.size();
    }

    vector<int> findLIS(vector<int>& nums, int previousIndex, int currentIndex) {
        if (currentIndex >= nums.size()) {
            return vector<int>();
        }

        if (LISs[previousIndex].size() > 0) {
            return LISs[previousIndex];
        }

        vector<int> takeCurrentIndex;
        if (previousIndex == nums.size() || nums[currentIndex] > nums[previousIndex]) {
            takeCurrentIndex = findLIS(nums, currentIndex, currentIndex + 1);
            takeCurrentIndex.push_back(nums[currentIndex]);
        }

        vector<int> skipCurrentIndex = findLIS(nums, previousIndex, currentIndex + 1);

        if (takeCurrentIndex.size() > skipCurrentIndex.size()) {
            LISs[previousIndex] = takeCurrentIndex;
        } else {
            LISs[previousIndex] = skipCurrentIndex;
        }

        return LISs[previousIndex];
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
