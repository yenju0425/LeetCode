#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i = i + 1){
            int a = nums[i];
            if(i > 0 and a == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n - 1; j = j + 1){
                int b = nums[j];
                if(j > i + 1 and b == nums[j - 1]){
                    continue;
                }
                int c = -(a + b);
                //searching for c (binary search)
                if(binary_search(nums.begin() + j + 1, nums.end(), c)){
                    vector<int> vect = {a, b, c};
                    ans.push_back(vect);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1,2,-2,-1};

    Solution *S = new Solution();

    vector<vector<int>> ans = S->threeSum(nums);

    int n = ans.size();
    int m = 3;

    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < m; j = j + 1){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}