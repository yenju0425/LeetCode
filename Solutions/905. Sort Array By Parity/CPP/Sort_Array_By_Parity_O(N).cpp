#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> sortArrayByParity(vector<int> &nums){
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            //find the first odd num from left
            while((nums[l] & 1) == 0 and l < r){
                l = l + 1;
            }

            //find the first even num from right
            while((nums[r] & 1) == 1 and l < r){
                r = r - 1;
            }

            //swap them
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;

            l = l + 1;
            r = r - 1;
        }

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