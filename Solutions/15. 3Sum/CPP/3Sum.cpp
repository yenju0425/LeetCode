#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());

        vector<vector<int>> three_Sum;
        int nums_size = nums.size();
        for(int i = 0; i < nums_size - 2; i = i + 1){
            //skipping same numbers
            if(i > 0 and nums[i] == nums[i - 1]){
                continue;
            }

            int left  = i + 1;
            int right = nums_size - 1;

            int offset = -nums[i];
            while(left < right){
                if(nums[left] + nums[right] > offset){
                    right = right - 1;
                }
                else if(nums[left] + nums[right] < offset){
                    left  = left  + 1;
                }
                else{ //solution found
                    three_Sum.push_back(vector<int>{nums[i], nums[left], nums[right]});

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

        return three_Sum;
    }
};

int main(){
    Solution* S = new Solution();
    
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    vector<vector<int>> three_Sum = S->threeSum(nums);

    int n = three_Sum.size();
    int m = 3;
    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < m; j = j + 1){
            cout << three_Sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}