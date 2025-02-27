#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main() {
    Solution S;

    int k = 2;
    vector<int> nums{3, 2, 1, 5, 6, 4};

    cout << S.findKthLargest(nums, k) << endl;

    return 0;
}
