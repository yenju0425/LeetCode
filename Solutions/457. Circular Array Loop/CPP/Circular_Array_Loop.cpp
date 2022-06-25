#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool circularArrayLoop(vector<int> &nums){
        int nums_size = nums.size();
        for(int i = 0; i < nums_size; i++){
            nums[i] = nums[i] % nums_size;
        }

        vector<int> visited(nums_size, -1);
        for(int i = 0; i < nums_size; i++){
            int cur_idx = i;
            int nxt_idx = (cur_idx + nums[cur_idx] + nums_size) % nums_size;
            
            visited[cur_idx] = i;
            while(cur_idx != nxt_idx and visited[nxt_idx] != i){
                //check direction
                if((nums[cur_idx] ^ nums[nxt_idx]) < 0){ //different direction, don't visit next
                    break;
                }

                //update cur_idx, nxt_idx
                cur_idx = nxt_idx;
                nxt_idx = (cur_idx + nums[cur_idx] + nums_size) % nums_size;
                
                //visit current index
                visited[cur_idx] = i;
            }
            if(cur_idx != nxt_idx and visited[nxt_idx] == i){ //found a non-selfLoop
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{-2,1,-1,-2,-2};

    cout << S->circularArrayLoop(nums) << endl;

    return 0;
}