#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> &nums){
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
            sum = sum + *i;
            maxSum = max(maxSum, sum);
            sum = max(sum, 0); //re-accumulate sum
        }

        return maxSum;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> nums{-2};

    cout << S->maxSubArray(nums) << endl;

    return 0;
}