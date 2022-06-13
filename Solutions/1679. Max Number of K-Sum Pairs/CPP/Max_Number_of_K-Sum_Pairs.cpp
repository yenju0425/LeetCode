#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int maxOperations(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
    
        int count = 0;

        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum > k){
                j = j - 1;
            }
            else if(sum < k){
                i = i + 1;
            }
            else{
                count = count + 1;
                j = j - 1;
                i = i + 1;
            }
        }

        return count;
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    int k = 5;
    vector<int> nums{1, 2, 3, 4};

    cout << S->maxOperations(nums, k) << endl;

    return 0;
}