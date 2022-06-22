#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders){
        int heights_size = heights.size();

        unsigned long totalCost = 0;
        unsigned long laddersCost = 0;
        vector<int> useLadders; 

        for(int i = 1; i < heights_size; i++){
            //calculate "how much" is the cost
            int cost = heights[i] - heights[i - 1];
            if(cost <= 0){
                continue;
            }

            //calculate "where" to insert the cost
            vector<int>::iterator iter = upper_bound(useLadders.begin(), useLadders.end(), cost, greater<int>());

            //update totalCost
            totalCost = totalCost + cost;

            //update laddersCost, "cost" should be covered by ladder
            if(useLadders.size() < ladders){
                laddersCost = laddersCost + cost;
                useLadders.insert(iter, cost);
            }
            else if(iter - useLadders.begin() < ladders){
                laddersCost = laddersCost + cost - useLadders.back();
                useLadders.insert(iter, cost);
                useLadders.pop_back();
            }

            if(totalCost - laddersCost > bricks){
                return i - 1;
            }
        }

        return heights_size - 1;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int bricks  = 10;
    int ladders = 2;
    vector<int> heights = {4,12,2,7,3,18,20,3,19};

    cout << S->furthestBuilding(heights, bricks, ladders) << endl;

    return 0;
}