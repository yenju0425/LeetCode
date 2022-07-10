#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int fillCups(vector<int> &amount){
        priority_queue<int> pq(amount.begin(), amount.end());

        int first  = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int stepConter = 0;
        while(first > 0 or second > 0){
            stepConter = stepConter + 1;
            pq.push(first  - 1);
            pq.push(second - 1);
            
            first  = pq.top();
            pq.pop();

            second = pq.top();
            pq.pop();
        }

        return stepConter;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> amount{4, 5, 4};

    cout << S->fillCups(amount) << endl;

    return 0;
}