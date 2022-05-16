#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> lis = LIS(nums, -1, 0); //-1: previous_i is null
        int n = lis.size();

        //this part is to show the fianl LIS result
        for(int i = n - 1; i >= 0; i = i - 1){
            cout << lis[i] << " ";
        }
        cout << endl;

        return n; 
    }

    vector<int> LIS(vector<int>& nums, int previous_i, int i){
        vector<int> s;
        if(i >= nums.size()){
            return s;
        }
        vector<int> take_n;
        if(previous_i == -1 or nums[i] > nums[previous_i]){
            take_n = LIS(nums, i, i + 1);
            take_n.push_back(nums[i]);
        }
        vector<int> skip_n = LIS(nums, previous_i, i + 1);
        if(take_n.size() > skip_n.size()){
            return take_n;
        }
        else{
            return skip_n;
        }
    }
};

int main(){
    vector<int> seq;

    for(int i = 0; i < 5; i++){
        seq.push_back(i);
    }

    Solution *S = new Solution();

    cout << S->lengthOfLIS(seq) << endl;

    return 0;
}