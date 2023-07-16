#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int min_length = 0;

        int i = 0, j = 0;
        while (j < nums.size() || sum > target) {
            if (sum <= target) {
                sum += nums[j];
                j++;
            }
            else if (sum > target) {
                sum -= nums[i];
                i++;
            }

            if (sum >= target) {
                min_length = (min_length == 0) ? j - i : min(min_length, j - i);
            }
        }

        return min_length;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    cout << S->minSubArrayLen(target, nums) << endl;

    return 0;
}