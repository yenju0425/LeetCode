#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            result = result ^ *iter;  // xor
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{4, 1, 2, 1, 2};

    cout << S.singleNumber(nums) << endl;

    return 0;
}
