#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> lis_multiverse;

public:
    int lengthOfLIS(vector<int>& nums) {
        int lengthOfnums = nums.size();
        for(int i = 0; i < lengthOfnums; i = i + 1){
            //using binary search to find out the timespace that we can develope from
            int index = lower_bound(lis_multiverse.begin(), lis_multiverse.end(), nums[i]) - lis_multiverse.begin();

            //multiverse start evolving......
            if(index >= lis_multiverse.size()){
                lis_multiverse.push_back(nums[i]);
            }
            else{
                lis_multiverse[index] = nums[i];
            }
        }
        return lis_multiverse.size(); 
    }
};

int main(){
    vector<int> seq;

    for(int i = 0; i < 999999; i++){
        seq.push_back(i);
    }

    Solution *S = new Solution();

    cout << S->lengthOfLIS(seq) << endl;

    return 0;
}