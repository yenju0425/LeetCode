#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        vector<vector<int>> four_Sum;

        int nums_size = nums.size();
        for(int i = 0; i < nums_size - 3; i++){
            //skipping same numbers
            if(i > 0 and nums[i] == nums[i - 1]){
                continue;
            }

            for(int j = i + 1; j < nums_size - 2; j++){
                //skipping same numbers
                if(j > i + 1 and nums[j] == nums[j - 1]){
                    continue;
                }

                int left  = j + 1;
                int right = nums_size - 1;

                int offset = target - nums[i] - nums[j];
                while(left < right){
                    if(nums[left] + nums[right] > offset){
                        right = right - 1;
                    }
                    else if(nums[left] + nums[right] < offset){
                        left  = left  + 1;
                    }
                    else{ //solution found
                        four_Sum.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        //skipping same numbers
                        while(nums[right] == nums[right - 1] and left < right){
                            right = right - 1;
                        }
                        right = right - 1;

                        //skipping same numbers
                        while(nums[left]  == nums[left  + 1] and left < right){
                            left  = left  + 1;
                        }
                        left  = left  + 1;
                    }
                }
            }
        }

        return four_Sum;
    }
};

int main(){
    Solution* S = new Solution();
    
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> fourSum = S->fourSum(nums, 0);

    int n = fourSum.size();
    int m = 4;
    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < m; j = j + 1){
            cout << fourSum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}