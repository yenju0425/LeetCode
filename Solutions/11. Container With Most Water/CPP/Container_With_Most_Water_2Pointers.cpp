//Reference: https://leetcode.com/problems/container-with-most-water/discuss/6089/Anyone-who-has-a-O(N)-algorithm/7268
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        int currentMax = 0;
        int height_size = height.size();

        int left  = 0;
        int right = height_size - 1;

        for(int i = 0; i < height_size - 1; i++){ //why ?
            int area = min(height[left], height[right]) * (right - left);
            currentMax = max(currentMax, area);

            if(height[left] < height[right]){
                left = left + 1;
            }
            else{
                right = right - 1;
            }
        }

        return currentMax;
    }
};

int main(){
    Solution S;

    //input
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << S.maxArea(height) << endl;

    return 0;
}
