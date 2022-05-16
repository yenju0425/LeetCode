#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> dp_len;
    vector<vector<int>> dp_seq;

public:
    int lengthOfLIS(vector<int>& nums){
        int lengthOfnums = nums.size();
        dp_len = vector<int>(lengthOfnums + 1, 0);
        dp_seq = vector<vector<int>>(lengthOfnums + 1, vector<int>());

        //buttomUp
        int lis = lengthOfnums;

        for(int i = lengthOfnums - 1; i >= 0; i = i - 1){
            int maxLength = 1;
            int nextIndex = lengthOfnums; //default: assume there is no nextIndex, nums[i] is the last number taken

            for(int j = i + 1; j < lengthOfnums; j = j + 1){
                if(nums[j] > nums[i]){ //if j is takeable: take j
                    int length = dp_len[j] + 1;
                    if(length > maxLength){ //update 
                        maxLength = length;
                        nextIndex = j;
                    }
                }
            }
            dp_len[i] = dp_len[nextIndex] + 1;
            dp_seq[i] = dp_seq[nextIndex];
            dp_seq[i].push_back(nums[i]);

            //update lis
            if(dp_len[lis] < dp_len[i]){
                lis = i;
            }
        }
        int sizeOflis = dp_len[lis];

        //this part is to show the fianl LIS result
        for(int i = sizeOflis - 1; i >= 0; i = i - 1){
            cout << dp_seq[lis][i] << " ";
        }
        cout << endl;

        return sizeOflis; 
    }
};

int main(){
    vector<int> seq;

    for(int i = 0; i < 8; i++){
        seq.push_back(i);
    }

    Solution *S = new Solution();

    cout << S->lengthOfLIS(seq) << endl;

    return 0;
}