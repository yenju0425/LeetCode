#include <iostream>
#include <algorithm>  
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> sortArrayByParity(vector<int> &nums){
        sort(nums.begin(), nums.end(), [](int a, int b){
            return ((a ^ b) & 1) ? b & 1 : a < b;
        });

        return nums;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{3, 1, 2, 4};

    vector<int> result = S->sortArrayByParity(nums);

    for(auto i : result){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}