#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> partialLIS;

public:
    int lengthOfLIS(vector<int>& nums) {
        for (const int& num : nums) {
            auto insertionIndex = lower_bound(partialLIS.begin(), partialLIS.end(), num);

            if (insertionIndex == partialLIS.end()) {
                partialLIS.push_back(num);
            }
            else {
                *insertionIndex = num;
            }
        }

        return partialLIS.size();
    }
};

int main() {
    Solution S;

    // input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
