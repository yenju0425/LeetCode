#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution{
public:
    int findUnsortedSubarray(vector<int>& nums){
        int sizeOfnums = nums.size();

        bool find_min = false;
        int minBound = numeric_limits<int>::max();
        for(int i = 0; i < sizeOfnums; i++){
            if(find_min == true){
                minBound = min(minBound, nums[i]);
            }
            else if(i != sizeOfnums - 1 and nums[i] > nums[i + 1]){
                find_min = true;
            }
        }

        bool find_max = false;
        int maxBound = numeric_limits<int>::min();
        for(int i = sizeOfnums - 1; i >= 0; i--){
            if(find_max == true){
                maxBound = max(maxBound, nums[i]);
            }
            else if(i != 0 and nums[i - 1] > nums[i]){
                find_max = true;
            }
        }

        int left = -1;
        for(int i = 0; i < sizeOfnums; i++){
            if(nums[i] > minBound){
                left = i;
                break;
            }
        }

        int right = -1;
        for(int i = sizeOfnums - 1; i >= 0; i--){
            if(nums[i] < maxBound){
                right = i;
                break;
            }
        }

        int size = right - left + 1;
        return (size > 1) ? size : 0;
    }
};

int main(){
    Solution* S = new Solution();
    vector<int> nums ={1, 2, 3, 2, 3, 3};
    cout << S->findUnsortedSubarray(nums) << endl;
    return 0;
}