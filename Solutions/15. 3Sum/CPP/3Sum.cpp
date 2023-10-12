#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> three_Sum;

        int nums_size = nums.size();
        for(int i = 0; i < nums_size - 2; ++i) {
            //skipping same numbers
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left  = i + 1;
            int right = nums_size - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0) {
                    right = right - 1;
                }
                else if(sum < 0) {
                    left  = left  + 1;
                }
                else { //solution found
                    three_Sum.push_back(vector<int> {nums[i], nums[left], nums[right]});

                    //skipping same numbers
                    while(nums[right] == nums[right - 1] && left < right) {
                        right = right - 1;
                    }
                    right = right - 1;

                    //skipping same numbers
                    while(nums[left]  == nums[left  + 1] && left < right) {
                        left  = left  + 1;
                    }
                    left  = left  + 1;
                }
            }
        }

        return three_Sum;
    }
};

int main() {
    Solution S;
    
    //input
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = S.threeSum(nums);

    for(auto i : result) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
