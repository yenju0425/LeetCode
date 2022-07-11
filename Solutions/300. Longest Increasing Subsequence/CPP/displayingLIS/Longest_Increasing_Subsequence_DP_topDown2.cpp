#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> dp_len;
    vector<vector<int>> dp_seq;

public:
    int lengthOfLIS(vector<int> &nums){
        int lengthOfnums = nums.size();
        dp_len = vector<int>(lengthOfnums + 1, -1); //dp_len.shape() = n + 1, initialized with "-1"
        dp_seq = vector<vector<int>>(lengthOfnums + 1, vector<int>()); //initialized every entry with empty vector

        vector<int> lis = LIS(nums, lengthOfnums, 0); //lengthOfnums: previous_i is null
        int sizeOflis = lis.size();

        //this part is to show the fianl LIS result
        for(int i = sizeOflis - 1; i >= 0; i = i - 1){
            cout << lis[i] << ' ';
        }
        cout << endl;

        return sizeOflis; 
    }

    vector<int> LIS(vector<int> &nums, int previous_i, int i){
        int lengthOfnums = nums.size();

        vector<int> s;
        if(i >= lengthOfnums){
            return s;
        }

        if(dp_len[previous_i] != -1){ //the sequence stored in the 2D-vector is valid
            return dp_seq[previous_i];
        }

        //The remianing section deal with the situation we can't decide the LIS immediately
        vector<int> s_skip_n = LIS(nums, previous_i, i + 1);
        vector<int> s_take_n; //default: assume n is untakeable
        if(previous_i == lengthOfnums or nums[i] > nums[previous_i]){//if n is takeable: take n
            s_take_n = LIS(nums, i, i + 1);
            s_take_n.push_back(nums[i]);
        }

        int skip_n = s_skip_n.size();
        int take_n = s_take_n.size();

        //update dp_len and dp_seq
        if(take_n > skip_n){
            dp_len[previous_i] = take_n;
            dp_seq[previous_i] = s_take_n;
            s = s_take_n;
        }
        else{
            dp_len[previous_i] = skip_n;
            dp_seq[previous_i] = s_skip_n;
            s = s_skip_n;
        }
        return s;
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