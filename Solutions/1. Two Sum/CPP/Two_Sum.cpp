#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> sortedNum = nums;
        sort(sortedNum.begin(), sortedNum.end());
        
        vector<int> ans;

        vector<int>::iterator low  = sortedNum.begin();
        vector<int>::iterator high = sortedNum.end() - 1;
        while(low != high){
            int sum = *low + *high;
            if(sum > target){
                high = high - 1;
            }
            else if(sum < target){
                low = low + 1;
            }
            else{ //solution found, get index
                for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter = iter + 1){
                    if(*iter == *low){
                        ans.push_back(iter - nums.begin());
                    }
                    else if(*iter == *high){
                        ans.push_back(iter - nums.begin());
                    }
                }
                break;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums ={3,2,4};

    Solution* S = new Solution();

    vector<int> result = S->twoSum(nums, 6);

    for(vector<int>::iterator i = result.begin(); i != result.end(); i = i + 1){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}