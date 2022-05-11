#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum > k){
                j--;
            }
            else if(sum < k){
                i++;
            }
            else{
                count++;
                j--;
                i++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    int k = 5;

    Solution* S = new Solution();
    cout << S->maxOperations(nums, k) << endl;;
    return 0;
}