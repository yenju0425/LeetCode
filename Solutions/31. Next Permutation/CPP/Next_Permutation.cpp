#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int> &nums){
        vector<int>::iterator i = nums.end() - 1;

        while(i != nums.begin() and *(i - 1) >= *i){
            i = i - 1;
        }

        reverse(i, nums.end());
        
        if(i != nums.begin()){
            iter_swap(i - 1, upper_bound(i, nums.end(), *(i - 1)));
        }
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{1, 4, 5, 3, 2};

    S->nextPermutation(nums);

    for(auto i : nums){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}