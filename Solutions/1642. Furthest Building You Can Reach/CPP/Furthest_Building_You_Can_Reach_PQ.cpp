#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> useLadders;

        int heights_size = heights.size();
        for (int i = 1; i < heights_size; i++) {
            int cost = heights[i - 1] - heights[i];
            if (cost > 0) {
                continue;
            }

            useLadders.push(cost);
            if (useLadders.size() > ladders) {
                bricks = bricks + useLadders.top();
                useLadders.pop();
            }

            if (bricks < 0) {
                return i - 1;
            }
        }

        return heights_size - 1;
    }
};

int main() {
    Solution S;

    int bricks  = 10;
    int ladders = 2;
    vector<int> heights{4, 12, 2, 7, 3, 18, 20, 3, 19};

    cout << S.furthestBuilding(heights, bricks, ladders) << endl;

    return 0;
}
