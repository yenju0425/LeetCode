#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        //iteratively pick 'a' and 'b', and look for 'c' using binary search
        int bias = numeric_limits<int>::max();
        int n = nums.size();
        for(int i = 0; i < n - 2; i = i + 1){
            int a = nums[i];

            //skipping same numbers
            if(i > 0 and a == nums[i - 1]){
                continue;
            }

            for(int j = i + 1; j < n - 1; j = j + 1){
                int b = nums[j];

                //skipping same numbers
                if(j > i + 1 and b == nums[j - 1]){
                    continue;
                }

                //looking for for c (binary search)
                int c = target - (a + b);
                vector<int>::iterator result = lower_bound(nums.begin() + j + 1, nums.end(), c);

                int right_bias = (result == nums.end())           ? numeric_limits<int>::max() : *result - c;
                int left_bias  = (result == nums.begin() + j + 1) ? numeric_limits<int>::max() : *(result - 1) - c;

                if(min(abs(bias), min(abs(right_bias), abs(left_bias))) == abs(right_bias)){
                    bias = right_bias;
                }
                else if(min(abs(bias), min(abs(right_bias), abs(left_bias))) == abs(left_bias)){
                    bias = left_bias;
                }
            }
        }
        return target + bias;
    }
};

int main(){
    Solution* S = new Solution();

    vector<int> nums{-1, 0, 1, 1, 55};

    cout << S->threeSumClosest(nums, 3) << endl;

    return 0;
}