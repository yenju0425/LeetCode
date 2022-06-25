#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    bool isPossible(vector<int> &target){
        priority_queue<int> pq(target.begin(), target.end());
        unsigned int sum = 0;
        for(vector<int>::iterator iter = target.begin(); iter != target.end(); iter++){
            sum = sum + *iter;
        }
    
        while(pq.top() != 1){
            int maxVal = pq.top();
            
            //pop
            pq.pop();
            sum = sum - maxVal;

            //check maxVal, sum
            if(sum > maxVal or sum == 0){ //stuck, but pq.top() != 1
                return false;
            }

            maxVal = maxVal % sum;

            //push
            sum = sum + maxVal;
            pq.push(maxVal ? maxVal : sum);
        }

        return true;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> target{8, 5};

    cout << S->isPossible(target) << endl;

    return 0;
}