#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int> &nums){
        int maxStraight = 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int nums_size = nums.size();
        for(int i = 0; i < nums_size; i++){
            //if nums[i] is the first of a straight
            if(!s.count(nums[i] - 1)){
                int straight = 1;
                while(s.count(nums[i] + straight)){
                    straight = straight + 1;
                }

                maxStraight = max(maxStraight, straight);
            }
        }

        return maxStraight;
    }
};
int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{100, 4, 200, 1, 3, 2};

    cout << S->longestConsecutive(nums) << endl;

    return 0; 
}