#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> lis_multiverse;
    vector<vector<int>> lis_history; //ex: lis_history[3] represents the full history of how we get to lis_multiverse[3]

public:
    int lengthOfLIS(vector<int>& nums) {
        int lengthOfnums = nums.size();
        for(int i = 0; i < lengthOfnums; i = i + 1){
            //using binary search to find out the timespace that we can develope from
            int index = lower_bound(lis_multiverse.begin(), lis_multiverse.end(), nums[i]) - lis_multiverse.begin();

            //multiverse start evolving......
            if(index >= lis_multiverse.size()){
                lis_multiverse.push_back(nums[i]);

                vector<int> history;
                if(index > 0){
                    history = lis_history[index - 1];
                }
                history.push_back(nums[i]);
                lis_history.push_back(history);
            }
            else{
                lis_multiverse[index] = nums[i];
                lis_history[index].pop_back(); //roll back to the previous generation
                lis_history[index].push_back(nums[i]);
            }
        }

        int sizeOflis = lis_multiverse.size();

        //this part is to show the fianl LIS result
        for(int i = 0; i < sizeOflis; i = i + 1){
            cout << lis_history[sizeOflis - 1][i] << " ";
        }
        cout << endl;

        //return the universe with longest history
        return sizeOflis; 
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