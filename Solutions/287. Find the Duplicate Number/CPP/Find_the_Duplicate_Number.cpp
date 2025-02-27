#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                return idx + 1;
            }

            nums[idx] = -nums[idx];
        }
        return 0;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{3, 1, 3, 2, 4};

    cout << S.findDuplicate(nums) << endl;

    return 0;
}
