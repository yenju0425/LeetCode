#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n;
        vector<int> result(size, 0);

        int i1 = 0;
        int i2 = 0;
        for (int i = 0; i < size; ++i) {
            if (i1 == m || (i2 != n && nums1[i1] > nums2[i2])) {
                result[i] = nums2[i2];
                i2        = i2 + 1;
            } else {
                result[i] = nums1[i1];
                i1        = i1 + 1;
            }
        }

        nums1 = result;
    }
};

int main() {
    Solution S;

    int m = 1;
    int n = 0;
    vector<int> nums1{1};
    vector<int> nums2{};

    S.merge(nums1, m, nums2, n);

    for (auto i : nums1) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
