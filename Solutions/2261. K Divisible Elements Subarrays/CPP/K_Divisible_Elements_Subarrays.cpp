#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int numOfnums = nums.size();

        vector<int> divisible_i;  // indeces of divisible elements
        int numOfDivisible = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % p == 0) {
                divisible_i.push_back(i);
                numOfDivisible++;
            }
        }

        set<vector<int>> divSubarrays;
        for (int i = 0, j = 0; i < numOfnums; i++) {
            int limit = -1;
            if (j + k >= numOfDivisible) {
                limit = numOfnums;
            } else {
                limit = divisible_i[j + k];
            }

            vector<int> subarray;
            for (int j = i; j < limit; j++) {
                subarray.push_back(nums[j]);
                divSubarrays.insert(subarray);
            }

            // update
            if (j < numOfDivisible && i == divisible_i[j]) {
                j++;
            }
        }

        return divSubarrays.size();
    }
};

int main() {
    Solution S;

    int k = 7;
    int p = 1;
    vector<int> nums{5, 11, 17, 13, 16, 9, 4, 9, 20};

    cout << S.countDistinct(nums, k, p) << endl;

    return 0;
}
