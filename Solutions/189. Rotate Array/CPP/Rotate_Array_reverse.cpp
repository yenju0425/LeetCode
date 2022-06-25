#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<int> &nums, int k){
        k = k % nums.size();
        reverse(nums.begin(),     nums.end());
        reverse(nums.begin(),     nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 3;
    vector<int> nums{-1, -100, 3, 99};

    S->rotate(nums, k);

    for(auto i : nums){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}