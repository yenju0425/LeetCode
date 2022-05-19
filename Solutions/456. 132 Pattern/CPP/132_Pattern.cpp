#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution{
public:
    bool find132pattern(vector<int>& nums){
        int nums_size = nums.size();
        vector<int> intervals;
        for(int i = 0; i < nums_size; i++){
            vector<int>::iterator pos = lower_bound(intervals.begin(), intervals.end(), nums[i], [](int lhs, int rhs){return lhs > rhs;});
            if((pos - intervals.begin()) % 2 == 1){
                if(*pos == nums[i]){
                    pos = pos + 1;
                }
                else{
                    return true;
                }
            }
            else{
                if(pos == intervals.end()){
                    intervals.push_back(nums[i]);
                    intervals.push_back(nums[i]);
                }
                else{
                    *pos       = nums[i];
                    *(pos + 1) = *(intervals.end() - 1);
                    intervals.erase(pos + 2, intervals.end());
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int> test{-2, 1, -2};

    Solution* S = new Solution();

    cout << S->find132pattern(test) << endl;

    return 0;
}