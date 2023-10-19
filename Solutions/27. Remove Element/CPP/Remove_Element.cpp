#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            if (nums[i] != val) {
                nums[counter] = nums[i];
                counter = counter + 1;
            }
        }

        return counter;
    }
};

int main() {
    Solution S;

    // inputs
    int val = 2;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int result = S.removeElement(nums, val);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
