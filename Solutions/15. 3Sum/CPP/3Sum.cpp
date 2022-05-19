#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //iteratively pick 'a' and 'b', and look for 'c' using binary search
        vector<vector<int>> threeSum;
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
                int c = -(a + b);
                //looking for for c (binary search)
                if(binary_search(nums.begin() + j + 1, nums.end(), c)){
                    threeSum.push_back(vector<int>{a, b, c});
                }
            }
        }
        return threeSum;
    }
};

int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution* S = new Solution();

    vector<vector<int>> threeSum = S->threeSum(nums);

    int n = threeSum.size();
    int m = 3;
    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < m; j = j + 1){
            cout << threeSum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}