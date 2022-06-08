#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int trap(vector<int> &height){
        int maxHeight = 0;
        int maxHeightId = 0;

        int height_size = height.size();
        for(int i = 0; i < height_size; i++){
            if(height[i] > maxHeight){
                maxHeight = height[i];
                maxHeightId = i;
            }
        }

        int water = 0;

        //scan from left
        for(int i = 0, waterLevel = 0; i < maxHeightId; i++){
            waterLevel = max(waterLevel, height[i]);
            water = water + waterLevel - height[i];
        }

        //scan from right
        for(int i = height_size - 1, waterLevel = 0; i > maxHeightId; i--){
            waterLevel = max(waterLevel, height[i]);
            water = water + waterLevel - height[i];
        }

        return water;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << S->trap(height) << endl;

    return 0;
}