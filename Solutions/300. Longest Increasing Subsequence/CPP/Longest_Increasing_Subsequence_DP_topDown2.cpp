#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> dp_len;

public:
    int lengthOfLIS(vector<int> &nums){
        int lengthOfnums = nums.size();
        dp_len = vector<int>(lengthOfnums + 1, -1); //dp_len.size() = n + 1, initialized with "-1"

        int lengthOflis = LIS(nums, lengthOfnums, 0); //lengthOfnums: previous_i is null

        return lengthOflis; 
    }

    int LIS(vector<int> &nums, int previous_i, int i){
        int lengthOfnums = nums.size();

        if(i >= lengthOfnums){
            return 0;
        }

        if(dp_len[previous_i] != -1){ //the sequence stored in the 2D-vector is valid
            return dp_len[previous_i];
        }

        //The remianing section deal with the situation we can't decide the LIS immediately
        int skip_n = LIS(nums, previous_i, i + 1);
        int take_n = 0; //default: assume n is untakeable
        if(previous_i == lengthOfnums or nums[i] > nums[previous_i]){//if n is takeable: take n
            take_n = LIS(nums, i, i + 1) + 1;
        }

        int lengthOflis = max(skip_n, take_n);
        dp_len[previous_i] = lengthOflis;
        return lengthOflis;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> seq;
    for(int i = 0; i < 10; i++){
        seq.push_back(i);
    }

    cout << S->lengthOfLIS(seq) << endl;

    return 0;
}