#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        int nums_size = nums.size();
        int counter = 0;
        for(int i = 1; i < nums_size; i++){
            if(nums[i] > nums[counter]){
                counter = counter + 1;
                nums[counter] = nums[i];
            }
        }
        return counter + 1;
    }
};

int main(){
    Solution* S = new Solution();

    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int result = S->removeDuplicates(nums);
    for(int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}