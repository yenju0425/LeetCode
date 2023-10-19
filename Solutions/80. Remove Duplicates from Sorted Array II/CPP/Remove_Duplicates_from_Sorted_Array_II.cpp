#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;

        vector<int>::iterator iter = nums.begin() + 1;
        while (iter != nums.end()) {
            if (*iter == *(iter - 1)) {
                if (counter >= 2) {
                    nums.erase(iter);
                }
                else {
                    counter = counter + 1;
                    iter = iter + 1;
                }
            }
            else {
                counter = 1;
                iter = iter + 1;
            }
        }

        return nums.size();
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{1, 1, 1, 2, 2, 3};

    cout << S.removeDuplicates(nums) << endl;

    return 0;
}
