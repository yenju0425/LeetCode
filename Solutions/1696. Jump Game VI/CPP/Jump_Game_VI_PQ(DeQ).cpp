#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution{
public:
    int maxResult(vector<int> &nums, int k){
        deque<int> DQ;
        DQ.push_back(0);

        int nums_size = nums.size();
        for(int i = 1; i < nums_size; i++){
            nums[i] = nums[i] + nums[DQ.front()];

            while(!DQ.empty() and nums[DQ.back()] <= nums[i]){
                DQ.pop_back();
            }

            DQ.push_back(i);

            while(DQ.front() <= i - k){
                DQ.pop_front();
            }
        }

        return nums.back();
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 2;
    vector<int> nums{100, -1, -100, -1, 100};

    cout << S->maxResult(nums, k) << endl;

    return 0;
}