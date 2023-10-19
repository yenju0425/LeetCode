#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> LISs;

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        LISs = vector<vector<int>>(n, vector<int>());

        int LISLengthIndex = 0;
        for (int i = n - 1; i >= 0; --i) {
            int nextIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j]) {
                    if (LISs[j].size() > LISs[nextIndex].size()) {
                        nextIndex = j;
                    }
                }
            }

            LISs[i] = LISs[nextIndex];
            LISs[i].push_back(nums[i]);

            if (LISs[i].size() > LISs[LISLengthIndex].size()) {
                LISLengthIndex = i;
            }
        }

        for (const int& num : LISs[LISLengthIndex]) {
            cout << num << " ";
        }
        cout << endl;

        return LISs[LISLengthIndex].size();
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
