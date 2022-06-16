#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int missingNumber(vector<int> &nums){
        int range = nums.size(); //from 0 ~ range

        vector<bool> checker(range + 1, false);

        for(int i = 0; i < range; i++){
            checker[nums[i]] = true;
        }

        for(int i = 0; i < range; i++){
            if(checker[i] == false){
                return i;
            }
        }

        return range;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};

    cout << S->missingNumber(nums) << endl;

    return 0;
}